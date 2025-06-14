โค็ดแสดงสถานะว่าตัว Pi boot เข้า os debian เสร็จแล้ว

คำส่งเมื่อ clone มาแล้ว

1 sudo apt install libgpiod-dev \\ ติดตั้ง library เพื่อใช้ในการcompile c/c++

2 gcc -o blink main.c -lgpiod \\ "gcc = compile c/c++" "-o bilnk = nameoutput" "main.c = target" "-lgpiod = สั่งให้ gcc ใช้ libgpiod (library)"

3 sudo ./blink \\ run file check

วิธีให้ os run file เมื่อ boot เสร็จ

1 sudo nano /etc/systemd/system/blink.service \\ สร้าง fill .service หรือ ย้ายไฟล์เอาก็ได้ sudo mv ./blink.service /etc/systemd/system/blink

[Uploading blink.service…]()[Unit]
Description=Blink LED on boot using libgpiod
After=network.target

...
[Service]
ExecStart=/usr/local/bin/blink
Restart=on-failure
User=root

[Install]
WantedBy=multi-user.target
...

2 sudo systemctl daemon-reload \\ ให้ systemd โหลด unit files ใหม่ทั้งหมด

3 sudo systemctl enable blink.service  \\ คำสั่งให้เริ่มrunอัตโนมัติเมื่อบูตเครื่อง

4 sudo systemctl start blink.service \\

5 sudo systemctl status blink.service \\ สถานะ

6 sudo reboot \\ reboot เครือง

![20250614_123722-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/fd283849-7813-419b-abf8-d263f9d3591c)
