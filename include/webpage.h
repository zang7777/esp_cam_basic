#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <Arduino.h>

const char index_html[] PROGMEM = R"rawliteral(
<!doctype html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <title>ESP32-CAM Stream</title>
    <link rel="stylesheet" href="/style.css">
</head>
<body>
    <div class="container">
        <h1>Live Feed</h1>
        <div style="position: relative;">
            <img src="" id="stream-view" alt="Waiting for stream...">
        </div>
        
        <div class="controls">
            <button onclick="capturePhoto()">Capture Photo</button>
            <button onclick="location.reload()">Refresh Stream</button>
        </div>
        <div class="status">Stream Latency: Ultra Low Mode</div>
    </div>

    <div id="modal">
        <img id="captured-image">
        <button onclick="closeModal()">Close & Resume</button>
        <button onclick="downloadImage()">Download</button>
    </div>

    <script src="/script.js"></script>
</body>
</html>
)rawliteral";

const char style_css[] PROGMEM = R"rawliteral(
:root {
    --primary: #00e5ff;
    --bg: #121212;
    --card: #1e1e1e;
    --text: #ffffff;
}
body {
    font-family: 'Segoe UI', Roboto, Helvetica, Arial, sans-serif;
    background-color: var(--bg);
    color: var(--text);
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    min-height: 100vh;
    margin: 0;
    padding: 20px;
}
h1 { margin-bottom: 20px; font-weight: 300; letter-spacing: 2px; text-transform: uppercase; border-bottom: 2px solid var(--primary); padding-bottom: 10px; }
.container {
    background: var(--card);
    padding: 20px;
    border-radius: 15px;
    box-shadow: 0 10px 30px rgba(0,0,0,0.5);
    text-align: center;
    max-width: 800px;
    width: 100%;
}
img {
    width: 100%;
    height: auto;
    border-radius: 8px;
    border: 1px solid #333;
    background: #000;
}
.controls { margin-top: 20px; display: flex; gap: 15px; justify-content: center; flex-wrap: wrap; }
button {
    background: transparent;
    color: var(--primary);
    border: 2px solid var(--primary);
    padding: 12px 24px;
    border-radius: 50px;
    font-size: 16px;
    font-weight: bold;
    cursor: pointer;
    transition: all 0.3s ease;
    text-transform: uppercase;
}
button:hover { background: var(--primary); color: #000; box-shadow: 0 0 15px var(--primary); }
button:active { transform: scale(0.95); }
.status { margin-top: 10px; font-size: 12px; color: #888; }

/* Modal for captured image */
#modal { display: none; position: fixed; z-index: 1000; left: 0; top: 0; width: 100%; height: 100%; background-color: rgba(0,0,0,0.9); align-items: center; justify-content: center; flex-direction: column; }
#modal img { max-height: 80%; max-width: 90%; width: auto; box-shadow: 0 0 20px #fff; }
#modal button { margin-top: 20px; border-color: #fff; color: #fff; }
#modal button:hover { background: #fff; color: #000; }
)rawliteral";

const char script_js[] PROGMEM = R"rawliteral(
const streamUrl = `${window.location.origin}:81/stream`;
const view = document.getElementById('stream-view');

// Start stream on load
window.onload = () => { view.src = streamUrl; };

function capturePhoto() {
    const modal = document.getElementById('modal');
    const capImg = document.getElementById('captured-image');
    
    // Fetch the capture endpoint
    fetch('/capture')
        .then(response => response.blob())
        .then(blob => {
            const url = URL.createObjectURL(blob);
            capImg.src = url;
            capImg.dataset.downloadUrl = url; // Store for download
            modal.style.display = 'flex';
        })
        .catch(err => alert('Capture failed!'));
}

function closeModal() {
    document.getElementById('modal').style.display = 'none';
}

function downloadImage() {
    const url = document.getElementById('captured-image').dataset.downloadUrl;
    const a = document.createElement('a');
    a.href = url;
    a.download = `esp32-capture-${Date.now()}.jpg`;
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
}
)rawliteral";

#endif // WEBPAGE_H
