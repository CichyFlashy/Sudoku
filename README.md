# Sudoku

## Opis
Program pozwala użytkownikom na rozwiązywanie plansz Sudoku o różnych rozmiarach (4x4, 9x9, 16x16) oraz poziomach trudności (Łatwy, Średni, Trudny). Gra oferuje funkcje takie jak wybór ruchu, wyświetlanie planszy, zapisywanie i wczytywanie gier, podpowiedzi, wyświetlanie czasu. 

## Funkcje
- **Generowanie planszy**: Automatyczne generowanie rozwiązywalnych plansz Sudoku.
- **Podpowiedzi**: Wyświetla dostępne wartości dla pustych komórek.
- **Zapisywanie i wczytywanie gry**: Możliwość zapisania postępu gry i kontynuowania później.
- **Poziomy trudności**: Możliwość wyboru łatwego, średniego lub trudnego poziomu trudności przy generowaniu układanki.
- **Wyświetlanie czasu**: Program śledzi, ile czasu minęło od rozpoczęcia gry.
- **Interfejs przyjazny użytkownikowi**: Gra posiada przejrzysty interfejs tekstowy, który prowadzi użytkownika przez kolejne etapy gry.

## Jak grać
1. **Zacznij nową grę**: Wybierz rozmiar planszy (4, 9 lub 16) oraz poziom trudności (1 – Łatwy, 2 – Średni, 3 – Trudny).
2. **Wykonaj ruch**: Wprowadź numer wiersza, kolumny oraz wartość, którą chcesz wstawić.
3. **Pokaż planszę**: Zobacz bieżący stan planszy.
4. **Podpowiedzi**: Otrzymaj listę dostępnych wartości dla pustej komórki.
5. **Zapisz grę**: Zapisz swój postęp do pliku i wróć do niego później.
6. **Wczytaj grę**: Wczytaj wcześniej zapisaną grę z pliku.

## Wymagania
- **Kompilator C**: Projekt napisany jest w języku C, do kompilacji i uruchomienia wymaga kompilatora C (np. GCC).
- **Biblioteki standardowe**: Program korzysta z bibliotek standardowych C (`stdio.h`, `stdlib.h`, `stdbool.h`, `time.h`).

## Jak uruchomić
1. Sklonuj repozytorium lub pobierz pliki.
2. Skompiluj program za pomocą kompilatora C:
   ```bash
   gcc -o sudoku sudoku.c

## Screeny działania
![image](https://github.com/user-attachments/assets/f00103f0-d901-46dd-b561-fa72009f0b2c)
