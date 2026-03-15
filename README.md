# 📷 ESP32-CAM Basic — Picture Capture & Refresh

> A minimal, beginner-friendly firmware for the **ESP32-WROVER-DEV** that captures images from the onboard camera and serves a live-refreshing web viewer over Wi-Fi.

---

## 📸 Preview

| Hardware Setup | Live Web Capture |
|:-:|:-:|
| ![Hardware Setup](https://github.com/zang7777/esp_cam_basic/blob/main/include/WhatsApp%20Image%202025-12-21%20at%201.09.22%20PM.jpeg?raw=true) | ![Live Capture](https://github.com/zang7777/esp_cam_basic/blob/main/include/esp32-capture-1766300986372.jpg?raw=true) |

---

## 🧰 Hardware Requirements

| Component | Details |
|---|---|
| Board | ESP32-WROVER-DEV |
| Camera Module | OV2640 (onboard) |
| Power Supply | 5V via USB |
| Wi-Fi | 2.4 GHz network |

---

## 🚀 Features

- 📷 Capture JPEG images from the ESP32-CAM module
- 🌐 Serve a web page that **auto-refreshes** the captured image
- ⚡ Lightweight C/C++ firmware with no heavy dependencies
- 🔧 Built with **PlatformIO** for easy setup and flashing

---

## 🛠️ Getting Started

### Prerequisites

- [PlatformIO IDE](https://platformio.org/) (VSCode extension recommended)
- ESP32 board support package
- USB-to-Serial adapter (if your board lacks one)

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/zang7777/esp_cam_basic.git
   cd esp_cam_basic
   ```

2. **Open in PlatformIO**
   - Open VSCode → PlatformIO Home → Open Project → select the cloned folder.

3. **Configure Wi-Fi credentials**
   - Edit the relevant source file in `src/` and set your `SSID` and `PASSWORD`.

4. **Build & Flash**

5. **Monitor Serial Output**

   - After boot, the board will print its **IP address** to the serial monitor.

6. **View the Camera Feed**
   - Open a browser and navigate to `http://<ESP32_IP_ADDRESS>/`
   - The page will display and periodically refresh the latest captured image.

---

## 📁 Project Structure

```
esp_cam_basic/
├── .vscode/          # VSCode workspace settings
├── include/          # Header files & assets (images)
├── lib/              # External libraries
├── src/              # Main firmware source code (C/C++)
├── test/             # Unit tests
├── .gitignore
└── platformio.ini    # PlatformIO build configuration
```

---

## ⚙️ Configuration (`platformio.ini`)

The project targets the **ESP32-WROVER-DEV** board. Key settings in `platformio.ini`:

```ini
[env:esp32dev]
platform  = espressif32
board     = esp32dev
framework = arduino
```

> Adjust `upload_port` and `monitor_speed` as needed for your system.

---

## 🌐 How It Works

1. On boot, the ESP32 connects to your Wi-Fi network.
2. The camera is initialized and begins capturing JPEG frames.
3. A lightweight HTTP server starts on port **80**.
4. Visiting the device's IP in a browser returns an HTML page that embeds the captured image and uses a **meta-refresh** tag to reload it at a set interval.

---

## 🐛 Troubleshooting

| Issue | Solution |
|---|---|
| Camera init failed | Check camera module seating and power supply |
| Can't connect to Wi-Fi | Verify SSID/password and use 2.4 GHz band |
| Image not refreshing | Try a hard browser refresh (`Ctrl+Shift+R`) |
| Upload fails | Hold the `BOOT` button on the board during flashing |

---


---

## 📄 License

This project is open source. See the repository for details.

---

## 🔗 Links

- **Repository:** [github.com/zang7777/esp_cam_basic](https://github.com/zang7777/esp_cam_basic)
- **PlatformIO Docs:** [docs.platformio.org](https://docs.platformio.org)
- **ESP32-CAM Datasheet:** [Espressif ESP32](https://www.espressif.com/en/products/socs/esp32)
