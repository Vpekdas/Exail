# Exail

## Screenshots

[https://github.com/user-attachments/assets/02bcae1d-40d3-4ed2-ad44-43b7bad11c7d](https://github.com/user-attachments/assets/dc70b092-6a82-465d-abab-473b659d927a)

## Table of Contents
1. [Description](#description)
2. [Installation](#installation)
3. [Run](#run)
4. [Credits](#credits)
5. [Contributing](#contributing)
6. [License](#license)

## Description

This prototype was for a technical test. It's a simple drone made in Unreal Engine 5.

### Purpose

The goal of this project was to create an element that can move using the keyboard or mouse. We could choose between C++ or Blueprints. The use of AI was encouraged.
I described my approach and usage of AI [here](README-APPROACH.md)

## Controls

| Key        | Action |
|:----------:|--------|
| `W` or `Z` | Move forward |
| `S`        | Move backward |
| `A` or `Q` | Move left |
| `D`        | Move right |
| `MOUSE`    | Rotate camera |

### Technologies used

- **Unreal Engine 5** – Version 5.7.4
- **C++** – Used for coding.
- **Visual Studio 2026** - IDE.
  
### Challenges and Future Features

I already had experience with Unity and Godot, so I knew a little bit how I would approach the code. The main challenge was finding the Unreal Engine 5 equivalent of Unity methods and components.

I also think it's worth mentioning that setting up and getting started with Unreal Engine 5 is much more tedious compared to Unity and Godot. I used the version from the Epic Games Launcher and ran into a couple of issues with Visual Studio 2026 builds or IntelliSense, even though it's the IDE recommended by Epic.

## Prerequisites

- Unreal Engine 5.7.4
- (For development) Visual Studio 2026 or 2022 or any IDE, but Unreal Engine 5 integrates well with Visual Studio.
- A C++ and C# compiler, if not already installed.

## Installation

Clone the repository:
`
git clone https://github.com/Vpekdas/Exail
`

## Run

### Play

If you simply want to play, you can double-click on `Exail.uproject`. Then play in Unreal Engine 5.
You can also edit level by placing any objects you want or my custom Blueprint `Boost` which gives speed boost when colliding.

### Development

> [!NOTE]
> I only tested the project on Windows, so unfortunately I can't guarantee that it will work on macOS or Linux. In a previous experience, I worked on a project on a MacBook Air with an M1 chip. The experience wasn't great, but the project ran well.

1) I recommend generating the `solution/project` instead of launching Unreal Engine 5 directly, whether you're using `Visual Studio` or `VS Code`. I don't know if it's the same for other IDEs. Right-click on `Exail.uproject` and generate the `solution/project`. Depending on your OS, this option may appear under a different name in the right-click menu.
2) Double-click on the `solution/project`. It should open your IDE, and from there you can start a `Development build`. Again, how you launch this build may differ depending on your IDE.
3) `Live Coding`, which is Unreal Engine 5's hot reloader, didn't work at all in my case, not a surprise xD. I recommend disabling it in the settings. If you plan to code mainly with C++ classes, you can create the class directly in Unreal Engine 5, then close the editor, rebuild, and recompile the project from your IDE. After that, each time you modify your code, rebuild and recompile it from your IDE.

## Credits

Thanks to the interviewer that sent me this test ! It was very cool to program and learn.

## Contributing

To report issues, please create an issue here:  [issue tracker](https://github.com/Vpekdas/Exail/issues).

If you'd like to contribute, please follow the steps outlined in [CONTRIBUTING.md](CONTRIBUTING.md).

## License

This project is licensed under the [MIT License](LICENSE).
