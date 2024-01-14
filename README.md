# Real Time Clock DS1302 za Raspberry Pi 2

(ovde ce biti dokumentacija, okvirno sta kod radi, glavne funkcije, instalacija, testiranje, reference odnosno sajtovi koje smo koristili i slicno)

## Instalacija

1.) Kopirati fajlove iz 'kod' foldera u lokaciju sa koje će se pozivati kod prilikom pokretanja sistema<br />
    > example: /home/stefziv/moj_program/<br />
2.) Kompajlirati kod pokretanjem komande:<br />
    > gcc rtc-pi-v3.c<br />
3.) Otvoriti rtcpi_daemon.service fajl i promeniti vrednost ExecStart na izabranu lokaciju:<br />
    > ExecStart=/home/stefziv/moj_program/a.out<br />
4.) Kopirati izmenjeni rtcpi_daemon.service na lokaciju:<br />
    > /etc/systemd/system/<br />
5.) Osvezavanje servisnih fajlova/
    > sudo systemctl daemon-reload<br />
6.) Ako zelimo da se servis pokrene prilikom svakog pokretanja sistema:<br />
    > sudo systemctl enable rtcpi_daemon.service<br />
7.) Za pokretanje servisa<br />
    > sudo systemctl start rtcpi_daemon.service<br />
8.) Provera stanja i pregled logova:<br />
    > sudo systemctl status rtcpi_daemon.service<br />