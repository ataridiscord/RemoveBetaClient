#include <iostream>
#include <curl/curl.h>
#include <Windows.h>
#include <string>
#include <format>
#include <filesystem>

__forceinline std::size_t writeFunction(void* ptr, std::size_t size, std::size_t nmemb, std::string* data)
{
    data->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

int main()
{
    std::string response{};
    std::string header{};
    long response_code{};

    SetConsoleTitleA("Roblox Beta Client Remover - atari#7353");

    std::cout << "Welcome! This program aims to help you easily remove the Roblox Beta Client and restore the old client we all know and love.\n";
    std::cout << "This project is licensed under: GNU GENERAL PUBLIC LICENSE\nhttps://github.com/atari-1337/RobloxBetaClientRemover/blob/main/LICENSE\n\n";
    std::cout << "[INFO] Fetching current Roblox version...\n";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    auto session = curl_easy_init();

    if (!session)
        return EXIT_FAILURE;

    curl_easy_setopt(session, CURLOPT_URL, "http://setup.roblox.com/version");
    curl_easy_setopt(session, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(session, CURLOPT_MAXREDIRS, 50L);
    curl_easy_setopt(session, CURLOPT_TCP_KEEPALIVE, 1L);

    curl_easy_setopt(session, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(session, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(session, CURLOPT_HEADERDATA, &header);

    auto code = curl_easy_perform(session);

    curl_easy_getinfo(session, CURLINFO_RESPONSE_CODE, &response_code);
    if (response_code != 200)
    {
        std::cout << "[ERROR] Failed to fetch current Roblox version.\n";
        std::getchar();
        return EXIT_FAILURE;
    }

    curl_easy_cleanup(session);
    curl_global_cleanup();

    std::cout << "[INFO] Current Roblox Version: " << response << '\n';

    const auto version_path = "C:\\Users\\" + std::string(getenv("username")) + "\\AppData\\Local\\Roblox\\Versions\\" + response;
    const auto launcher_path = version_path + "\\RobloxPlayerLauncher.exe";
    const auto client_path = version_path + "\\RobloxPlayerBeta.exe";

    if (std::filesystem::exists(version_path) && std::filesystem::exists(launcher_path) && std::filesystem::exists(client_path))
    {
        std::cout << "[INFO] Removing the beta client...\n";
        std::filesystem::remove(client_path);
        std::cout << "[INFO] This program will run the Roblox Launcher as an Administrator for the process to complete. If asked by UAC, please click \"Yes\" so that the launcher runs correctly.\n";
        std::getchar();
        system(std::format("runas.exe / savecred / user:administrator {}", launcher_path).c_str());

        std::cout << "[INFO] If the launcher opened correctly and finished installing, the operation has succeeded.\n";
        std::getchar();

        return EXIT_SUCCESS;
    }

    std::cout << "[ERROR] Failed to locate one or more of 3 required paths. Please check to make sure they exist.\n";
    std::getchar();
    return EXIT_FAILURE;
}