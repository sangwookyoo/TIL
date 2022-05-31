### 📌 VSCODE - Unity
1. Install the [.NET Core SDK](https://dotnet.microsoft.com/download), which includes the Runtime and the `dotnet` command.
2. [Windows only] Logout or restart Windows to allow changes to `%PATH%` to take effect.
3. [macOS only] To avoid seeing "Some projects have trouble loading. Please review the output for more details", make sure to install the latest stable [Mono](https://www.mono-project.com/download/stable/) release.
    <b>Note</b>: This version of Mono, which is installed into your system, will not interfere with the version of MonoDevelop that is installed by Unity.
4. Install extension from the VSCODE Marketplace.
    - [C#](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
    - [Debugger for Unity](https://marketplace.visualstudio.com/items?itemName=Unity.unity-debug)
    - [Unity Code Snippets](https://marketplace.visualstudio.com/items?itemName=kleber-swf.unity-code-snippets)
    - [Unity Tools](https://marketplace.visualstudio.com/items?itemName=Tobiah.unity-tools)

- VSCODE - Preference - C# configuration - omnisharp.useModernNet: `false`
- Unity - Preference - External Tools - External Script Editor: `Visual Studio Code`
- Unity - Paackage Manager: `Visual Studio Code Editor`
