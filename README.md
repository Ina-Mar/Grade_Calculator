# Grade_Calculator
Studentų galutinio pazymio skaičiuoklė
Programa apskaičiuoja galutinį pažymį pagal nustatytą formulę ir atspausdina rezaultatus konsolės lange arba išveda į tekstinius failus.
Programos naudojimas.
Programa turi Setup failą, kurį galima naudoti jos įdiegimui į Windows sistemą. Paleidus Setup.exe failą, pradedamas programos diegimas. Dialogo lange reikia pasirinkti vietą, į kurią bus įdiegta programa. Užbaigus diegimą, darbastalyje ir programų sąraše atsiras nuorodos į programą GradeCalculator. Paleidus šią programą, atsidaro konsolės langas, kuriame naudotojo prašoma pasirinkti duomenų įvedimą iš konsolės arba iš failo. Pasirinkimas šiuo ir visais kitais atvejais daromas įvedant atitinkamą raidę. Toliau prašoma pasirinkti galutinio pažymio skaičiavimą pagal vidurkį arba pagal medianą. 
Pasirinkus įvedimą iš konsolės, prašoma nurodyti, kelių studentų duomenis norima įvesti. Duomenys turėtų būti įvedami tokia tvarka: Vardas Pavardė pažymiai galutinis balas. Duomenys privalo būti atskirti tarpais, atskiro studento duomenų įvedimas baigiamas įvedus 0. Pasirinkus įvestį iš failo, reikia nurodyti sąlyginį (pvz., "text.txt") arba absoliutų (pvz., "C:/../../text.txt") vardą failo, iš kurio bus nuskaitomi duomenys. (Pastaba. Norint apskaičiuoti vidurkį pagal medianą, pažymių kiekis turėtų būti ne mažesnis nei 3).
Baigus duomenu ivedima, naudotojui leidžiama pasirinkti apskaičiuotų rezultatų išvedimą į konsolę arba į failus. Į konsolę programa išveda abėcėlės tvarka pagal pavardes surūšiuotus studentus. Pasirinkus išvedimą į failus, duomenys surūšiuojami pagal teigiamą arba neigiamą galutinį balą ir išvedami į du naujus failus. Naudotojui leidžiama pasirinkti išvesties failų vardus. Jeigu failai nepasirenkami arba jų formatas yra netinkamas, programa pati sukuria atitinkamus failus. Išvedus failus, naudotojui pranešami jų vardai.

Programos versijos.
Versija v0.1.
Šioje versijoje sukurtas pagrindinis duomenų nuskaitymo ir skaičiavimo mechanizmas.

Versija v0.2.
Sukurta funkcija, leidžianti kurti tekstinius failus su studentų sąrašais, pažymius ir egzamino rezultatą generuojant atsitiktinių skaičių generatoriumi. 
Sukurtas studentų rūšiavimas į dvi grupes pagal tai, ar galutinis balas yra teigiamas pažymys, ir šių grupių duomenų surašymas į du naujus failus.
Atliktas testavimas matuojant programos spartą, kai kuriami nauji failai, jie nuskaitomi, duomenys rūšiuojami ir išvedami į naujus failus naudojant vector tipo konteinerius.
Po to sukurti atitinkami nuskaitymo ir rūšiavimo būdai list ir deque tipo konteineriams. Testuojant paaiškėjo, kad nuskaitymas ir rūšiavimas greičiausiai vykdomas naudojant list konteinerius.

Versija 1.0.
Išmatuota programos veikimo sparta rūšiuojant duomenis dviem skirtingais būdais. Pirmasis būdas - rasti pažangius studentus duotame konteineryje ir perkelti juos į naują konteinerį, pašalinant iš senojo. Antras būdas - studentus išrūšiuoti į du naujus konteinerius pagal pažangumą.
Testavimo rezultatai.
Studentų rūšiavimas į vieną vektorių trunka ilgiausiai. Rūšiavimas vienu metu į du vektorius leidžia žymiai sutrumpinti proceso trukmę. Rūšiavimas naudojant list tipo konteinerius abiem atvejais yra pats greičiausias. Rūšiavimas į vieną deque konteinerį trunka ilgiau negu rūšiavimas į atitinkamą vektorių, bet rūšiavimas į du deque konteinerius yra efektyvesnis nei rūšiavimas į du vektorius.

Po to atliktas studentų rūšiavimo naudojant vektoriaus tipo konteinerius optimizavimas. Naudojant algoritmus count_if ir partition_copy pavyko gerokai pagreitinti rūšiavimą. Galutinė rūšiavimo į vektorius versija greičiu kai kuriais atvejais pranoksta rūšiavimą į list konteinerius.

Programos veikimo analizės testus galima atlikti GradeCalculator.cpp paleidus testing funkciją.







