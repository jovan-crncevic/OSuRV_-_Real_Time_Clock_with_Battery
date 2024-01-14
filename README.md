# Real Time Clock DS1302 za Raspberry Pi 2

(ovde ce biti dokumentacija, okvirno sta kod radi, glavne funkcije, instalacija, testiranje, reference odnosno sajtovi koje smo koristili i slicno)

## Instalacija

1.) Kopirati fajlove iz 'kod' foldera u lokaciju sa koje će se pozivati kod prilikom pokretanja sistema<br />
>   example: /home/stefziv/moj_program/<br />
2.) Kompajlirati kod pokretanjem komande:<br />
>   gcc rtc-pi-v3.c<br />
3.) Otvoriti rtcpi_daemon.service fajl i promeniti vrednost ExecStart na izabranu lokaciju:<br />
>   ExecStart=/home/stefziv/moj_program/a.out<br />
4.) Kopirati izmenjeni rtcpi_daemon.service na lokaciju:<br />
>   /etc/systemd/system/<br />
5.) Osvežavanje servisnih fajlova<br />
>   sudo systemctl daemon-reload<br />
6.) Ako želimo da se servis pokrene prilikom svakog pokretanja sistema:<br />
>   sudo systemctl enable rtcpi_daemon.service<br />
7.) Za pokretanje servisa<br />
>   sudo systemctl start rtcpi_daemon.service<br />
8.) Provera stanja i pregled logova:<br />
>   sudo systemctl status rtcpi_daemon.service<br />

## Testiranje

1.) Povezati sve pinove sa raspberry pločom na sledeći način:<br />
VCC - 2 pin (NE TREBA AKO SE KORISTI BATERIJA)<br />
GND - 6 pin (NE TREBA AKO SE KORISTI BATERIJA)<br />
CLK - 13 pin GPIO27<br />
DAT - 12 pin GPIO18<br />
RST - 11 pin GPIO17<br />
2.) Povezati ostale kablove i pokrenuti raspi<br />
3.) Kad se sistem pokrene, ući u terminal:<br />
>   journalctl -xe | grep RTCPI<br />
4.) Promeniti sat na raspiju u drugom terminalu:<br />
>   sudo date -s '2021-01-04 13:04:00'<br />
5.) U prvom terminalu pokrenuti istu komandu<br />
6.) Povezati raspi na internet i posmatrati log posle par minuta<br />
7.) ...<br />