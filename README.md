# 🏎️ Crazy Taxi Arcade PC Port v1.0

Welcome to the official GitHub repository for the **Crazy Taxi (1999)** PC Porting project, targeted at the **Sega NAOMI** Arcade motherboard. 

This project features a native **C++ (x64)** Launcher built with the **SDL2** library and fully optimized using the official **Windows 11 SDK**. The launcher manages safe ROM injection and bypasses original arcade BIOS verification using a streamlined, built-in MAME No-BIOS architecture.

---

## 💻 System Requirements

To ensure a smooth execution of both the Launcher and the 3D graphics engine, your computer must meet the following technical specifications.

### 📌 Minimum Requirements (To run the game)
*   **Operating System:** Windows 10 (Version 22H2 / Build 19045 or higher) or Windows 11 — **64-bit only**. *(32-bit systems are not supported).*
*   **Processor (CPU):** Intel Core i3 / AMD Ryzen 3 (Quad-Core released after 2015) with a minimum clock speed of **2.0 GHz**.
*   **Memory (RAM):** **4 GB** of free RAM.
*   **Graphics Card (GPU):** NVIDIA GeForce GT 730 / AMD Radeon R7 or integrated Intel HD Graphics 500 (or higher) with native **DirectX 11** support.
*   **Download Size:** **~170 MB** (Compressed .zip archive).
*   **Disk Space:** **250 MB** of available hard drive space once extracted.

### 🚀 Recommended Requirements (For stable 60 FPS in High Definition)
*   **Operating System:** Windows 11 64-bit (Versions 22H2, 23H2, or 24H2). *Optimized to fully leverage the native APIs used during compilation.*
*   **Processor (CPU):** Intel Core i5 (10th Gen or newer) / AMD Ryzen 5 with a clock speed of **3.5 GHz** or higher. *(Arcade hardware emulation heavily relies on strong single-core CPU performance).*
*   **Memory (RAM):** **8 GB** or **16 GB** of RAM configured in Dual-Channel mode.
*   **Graphics Card (GPU):** NVIDIA GeForce GTX 1050 Ti / AMD Radeon RX 560 or higher. *(Required to process advanced Direct3D scaling filters seamlessly).*
*   **Disk Space:** Installed on an **SSD** drive. *(Drastically cuts loading times and optimizes raw chip layout injection into the RAM).*
*   **Peripherals:** PC Gaming Controller (Xbox / PlayStation layout) or a fully remappable keyboard.

---

## 🛠️ Compilation & Compatibility Notes

The source code was successfully compiled using the **Visual Studio 2026** development environment under the **Release x64** target. Integrating the native Windows 11 SDK ensures full memory alignment protection against standard *Access Violation* (`0xc0000005`) errors and enables auto-scaling screen resolution parameters that adapt directly to the user's active monitor layout.

---

## ❓ Frequently Asked Questions (FAQ)

### 1. The game crashes instantly upon launch. How do I fix it?
Make sure your game folder is named exactly `roms` and that it contains the properly renamed `crzytaxi.zip` file. If your downloaded file is in a `.rar` format, you must extract it and re-compress it as a `.zip` archive, otherwise the engine won't be able to read the raw cart data.

### 2. Do I need to download the Naomi BIOS file (`naomi.zip`) separately?
No. This project uses a decrypted, No-BIOS version of the ROM. The original arcade operating system code is already pre-injected into the game chips, meaning the game is completely standalone and does not require external BIOS files.

### 3. How can I map my controller buttons or keyboard keys?
Once the game starts via the Launcher, press the **TAB** key on your keyboard to open MAME's built-in configuration overlay. Navigate to **Input (this Machine)**, highlight the command you want to change, press Enter, and then push your preferred button on your controller or keyboard. Press TAB again to save and close.

### 4. Will the Launcher remember my button mapping the next time I play?
Yes. The Launcher is programmed to automatically save your input layouts inside the local `cfg` folder. Do not delete this folder, or you will lose your custom controller configurations.

### 5. Can I play in Widescreen (16:9) without stretching the image?
Currently, the game runs in its native 4:3 arcade aspect ratio to preserve the core 3D proportions. Native **Widescreen support is planned for a future update** and will be implemented in upcoming releases.

### 6. Does the game support 4K resolution?
At the moment, the game scales automatically to match your current standard display resolution. True, native **4K Ultra HD rendering support will be arriving in a future development milestone**.

---

## 👥 Credits & Development Team

This PC porting project was made possible thanks to the passion, reverse engineering, and programming efforts of the following team:

*   **Development Studio:** **Fan Creation Studios** — An independent fan-driven group dedicated to preserving classic arcade history and bringing retro gems to modern PC hardware.
*   **Lead Programmer & Publisher:** **Azoto45** — Responsible for the core C++ architecture, custom input mapping hooks, Windows 11 API optimizations, and launcher design.

### 📜 Special Thanks & Acknowledgments
*   **SEGA® & Hitmaker:** The original creators of *Crazy Taxi* (1999) and the legendary SEGA NAOMI arcade hardware. This project is a non-profit fan tribute and holds no official affiliation with SEGA.
*   **The MAME Team:** For their incredible, long-standing open-source work on arcade hardware documentation and software emulation frameworks.
