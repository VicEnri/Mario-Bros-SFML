# 🎮 Mario Bros SFML

> **Versione attuale**: Beta — basata su SFML 3.0.0

## 🚀 Descrizione

Questo progetto è una rivisitazione di *Super Mario Bros* realizzata in C++ con **SFML 3.0.0**. L'obiettivo principale è sperimentare grafica 2D, gestione degli stati, input e collisioni.

## ✨ Funzionalità attuali

- Schermata iniziale con pulsante **INIZIA** animato.
- Schermata di **Game Over** con pulsante **RIPROVA**.
- Contatore monete (HUD).
- Mappa caricata da immagine (`TestMap.png`).
- Movimento e salto di Mario.
- Camera dinamica.
- Collisioni base.
- Riavvio partita con **RIPROVA**.

## 💡 Controlli

- Freccia destra/sinistra → Movimento.
- Freccia su → Salto.
- Mouse → Pulsanti INIZIA/RIPROVA.

## 🗺️ Stato attuale

- Avvio gioco cliccando **INIZIA**.
- Movimento base e raccolta monete.
- Fine partita se Mario cade o scontra Goomba(non da sopra).
- Riavvio con **RIPROVA**.

## 📄 Struttura progetto

```
Mario-Bros-SFML/
├── assets/
│   ├── fonts/
│   │   ├── mario.ttf
│   │   └── mario2.TTF
│   └── images/
│       ├── Coin/Coin2.png
│       └── Map/TestMap.png
├── headers/
├── src/
└── CMakeLists.txt
```

## ⚙️ Requisiti

- SFML 3.0.0
- C++17+
- CMake >= 3.16

## 🏁 Compilazione

```bash
git clone https://github.com/VicEnri/Mario-Bros-SFML.git
cd Mario-Bros-SFML
mkdir build && cd build
cmake ..
make
```

## 🔮 Futuro

- Più livelli.
- Sistema punteggio.
- Più giocatori.

## 🗒️ Note sullo sviluppo

Durante lo sviluppo ho creato **10 release** nel modo sbagliato, perché ho dovuto dividere il progetto in **9 tappe** per implementare e testare gradualmente le varie funzionalità.

## ❤️ Credits

Progetto didattico per approfondire C++ e SFML.
