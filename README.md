# RobloxBetaClientRemover
A simple tool that I created which restores the old Roblox client that we all know and love. The reasoning as to why this was created is because Roblox forced their beta client onto all users - making most of the Roblox community unhappy with the decision.

NOTE: This is a remake of [Cy's project](https://github.com/CyOfficial/RobloxBetaClientRemover), which he made in Python.

## Summary
The program will first find the latest version of Roblox. Once done, it will scan for the version path, the launcher path and the client path.

![](https://media.discordapp.net/attachments/1004563672766619681/1020407109822709910/unknown.png)

Once done, it'll remove the current Roblox client and run the Launcher as an Administrator.

## How to Compile
You can download a compiled version [here](https://github.com/atari-1337/RobloxBetaClientRemover/releases/download/V1/Compiled.zip)

NOTE: Ensure you follow these steps or it'll most likely fail to build.

1. If you want to use build this project, you need to setup a few things. First, install [Visual Studio 2022](https://www.visualstudio.com/downloads/).

2. Install [vcpkg](https://github.com/Microsoft/vcpkg)

3. Open Command Prompt and type the following:

```dos
cd /path/to/vckpg
```

4. Once you've changed your directory to the vcpkg path - you can continue by typing in the following:

```dos
vcpkg install curl:x64-windows
```

5. Wait for it to install - once done, type the following:

```dos
vcpkg integrate install
```

6. Download the source code [here](https://github.com/atari-1337/RobloxBetaClientRemover/releases/download/V1/RobloxBetaClientRemover.zip) and open it in Visual Studio.

7. Enjoy <3

## License
This project is licensed under the GNU General Public License v3.0. See the [LICENSE](https://github.com/atari-1337/RobloxBetaClientRemover/blob/main/LICENSE) file for more information.
