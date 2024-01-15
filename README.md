# Real Time Clock DS1302 za Raspberry Pi 2

## Svrha programa
- RTC (Real-Time Clock) čipovi se koriste za praćenje realnog vremena u stvarnom svetu, nezavisno od rada računara.<br />
- Opšta svrha ovog programa je upravljanje RTC čipom DS1302 povezanim sa Raspberry Pi računarom.<br />
- Ovaj program ima dva osnovna režima rada:<br />
Postavljanje vremena na RTC prilikom pokretanja - prilikom pokretanja programa čita se trenutno vreme i datum sa RTC čipa i postavlja se na sistemski sat Raspberry Pi- ja; ovo obezbeđuje da sistem ima tačno vreme pri svakom pokretanju<br />
Čekanje na promene u sistemu i ažuriranje RTC- a - prate se promene u sistemu; kada dođe do promene, čita se trenutno vreme sa Raspberry Pi- ja i upisuje se na RTC čip. Ovo omogućava održavanje tačnosti RTC- a u odnosu na sistemsko vreme Raspberry Pi- ja<br />

## Opis funkcija programa
- main() - ovo je glavna funkcija programa; postavlja GPIO pinove, sinhronizuje vreme sa RTC- om prilikom pokretanja, a zatim čeka na promene u sistemu kako bi se ažurirao RTC
- setup_io() - funkcija postavlja pristup GPIO pinovima Raspberry Pi računara; koristi se za mapiranje fizičkih adresa GPIO registara u virtuelni adresni prostor programa; podešava pinove za komunikaciju sa RTC čipom, postavljajući ih kao izlazne ili ulazne, i postavlja njihove početne vrednosti
- read_rtc() - funkcija čita vrednost iz određenog registra RTC čipa u svrhu čitanja informacija o trenutnom vremenu i datumu sa RTC čipa

## Instalacija

- Kopirati fajlove iz 'kod' foldera u lokaciju sa koje će se pozivati kod prilikom pokretanja sistema<br />
>   example: /home/stefziv/moj_program/<br />
- Kompajlirati kod pokretanjem komande:<br />
>   gcc rtc-pi-v3.c<br />
- Otvoriti rtcpi_daemon.service fajl i promeniti vrednost ExecStart na izabranu lokaciju:<br />
>   ExecStart=/home/stefziv/moj_program/a.out<br />
- Kopirati izmenjeni rtcpi_daemon.service na lokaciju:<br />
>   /etc/systemd/system/<br />
- Osvežavanje servisnih fajlova<br />
>   sudo systemctl daemon-reload<br />
- Ako želimo da se servis pokrene prilikom svakog pokretanja sistema:<br />
>   sudo systemctl enable rtcpi_daemon.service<br />
- Za pokretanje servisa<br />
>   sudo systemctl start rtcpi_daemon.service<br />
- Provera stanja i pregled logova:<br />
>   sudo systemctl status rtcpi_daemon.service<br />

## Testiranje

- Povezati sve pinove sa raspberry pločom na sledeći način:<br />
VCC - 2 pin (NE TREBA AKO SE KORISTI BATERIJA)<br />
GND - 6 pin (NE TREBA AKO SE KORISTI BATERIJA)<br />
CLK - 13 pin GPIO27<br />
DAT - 12 pin GPIO18<br />
RST - 11 pin GPIO17<br />
- Povezati ostale kablove i pokrenuti raspi<br />
- Kad se sistem pokrene, ući u terminal:<br />
>   journalctl -xe | grep RTCPI<br />
- Promeniti sat na raspiju u drugom terminalu:<br />
>   sudo date -s '2021-01-04 13:04:00'<br />
- U prvom terminalu pokrenuti istu komandu<br />
- Povezati raspi na internet i posmatrati log posle par minuta<br />
- ...<br />
