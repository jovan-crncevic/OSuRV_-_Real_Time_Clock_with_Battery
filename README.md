# Real Time Clock DS1302 za Raspberry Pi 2

(ovde ce biti dokumentacija, okvirno sta kod radi, glavne funkcije, instalacija, testiranje, reference odnosno sajtovi koje smo koristili i slicno)

## Instalacija

1.) Kopirati fajlove iz 'kod' foldera u lokaciju sa koje će se pozivati kod prilikom pokretanja sistema/
    > example: /home/stefziv/moj_program/
2.) Kompajlirati kod pokretanjem komande:/
    > gcc rtc-pi-v3.c
3.) Otvoriti rtcpi_daemon.service fajl i promeniti vrednost ExecStart na izabranu lokaciju:/
    > ExecStart=/home/stefziv/moj_program/a.out
4.) Kopirati izmenjeni rtcpi_daemon.service na lokaciju:/
    > /etc/systemd/system/
5.) Osvezavanje servisnih fajlova/
    > sudo systemctl daemon-reload
6.) Ako zelimo da se servis pokrene prilikom svakog pokretanja sistema:/
    > sudo systemctl enable rtcpi_daemon.service
7.) Za pokretanje servisa/
    > sudo systemctl start rtcpi_daemon.service
8.) Provera stanja i pregled logova:/
    > sudo systemctl status rtcpi_daemon.service 