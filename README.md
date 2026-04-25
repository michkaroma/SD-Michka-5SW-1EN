# SD-Michka-5SW-1EN — DIY Stream Deck

Un stream deck fait maison basé sur un **Pro Micro (ATmega32U4)**, avec 5 switchs mécaniques MX et un encodeur rotatif, développé sous **PlatformIO**.

---

## Contenu du dépôt

```
SD-Michka-5SW-1EN/
├── 3D/                     # Fichiers de conception du boîtier
│   ├── Deck v2.3mf         # Fichier d'impression 3D (3MF)
│   └── Deck v2.f3d         # Fichier source Fusion 360
├── README.md
└── StreamDeck/             # Projet PlatformIO
    ├── include/
    ├── lib/
    ├── src/
    │   └── main.cpp        # Code source principal
    ├── test/
    └── platformio.ini      # Configuration PlatformIO
```

---

## Matériel

| Composant | Quantité | Rôle |
|---|---|---|
| Arduino Pro Micro (ATmega32U4) | 1 | Microcontrôleur principal |
| Switch mécanique MX | 5 | Contrôles multimédia |
| Encodeur rotatif numérique | 1 | Volume / Mute |
| Boîtier imprimé en 3D | 1 | Coque du projet |

---

## Fonctionnalités

### Switchs MX

| Switch | Action |
|---|---|
| SW1 | ⏮ Piste précédente |
| SW2 | ⏪ Retour rapide |
| SW3 | ⏯ Play / Pause |
| SW4 | ⏩ Avance rapide |
| SW5 | ⏭ Piste suivante |

### Encodeur rotatif

| Geste | Action |
|---|---|
| Rotation | 🔊 Volume général +/− |
| Appui | 🔇 Mute |

---
 
## Branchements
 
### Switchs MX — broches digitales
 
Chaque switch MX a deux bornes. Le câblage est identique pour tous :
 
| Switch | Borne 1 | Borne 2 |
|---|---|---|
| SW1 | D4 | GND |
| SW2 | D5 | GND |
| SW3 | D6 | GND |
| SW4 | D7 | GND |
| SW5 | D8 | GND |
 
> Les résistances pull-up sont **internes** à l'ATmega32U4 (`INPUT_PULLUP`), aucune résistance externe n'est nécessaire.
<br>
 
### Encodeur rotatif — broches d'interruption externe
 
Les broches CLK et DT **doivent obligatoirement** être connectées à des broches d'interruption externe pour une lecture fiable.
 
| Broche encodeur | Broche Pro Micro | Interruption |
|---|---|---|
| CLK | D0 | INT2 |
| DT | D1 | INT3 |
| SW (mute) | D9 | — (digital classique) |
| VCC | VCC | — |
| GND | GND | — |
 
---

## Prérequis logiciels

- [PlatformIO](https://platformio.org/) (VS Code ou CLI)
- Bibliothèque **HID-Project** (NicoHood)

---

## Installation & Flash

```bash
# Cloner le dépôt
git clone https://github.com/michkaroma/SD-Michka-5SW-1EN.git

# Compiler et flasher via PlatformIO
cd SD-Michka-5SW-1EN/StreamDeck
pio run --target upload
```

---

## Impression 3D

Les fichiers du boîtier se trouvent dans le dossier `3D/` :
- **`.3mf`** → à ouvrir directement dans votre slicer (PrusaSlicer, Bambu Studio, Cura…)
- **`.f3d`** → fichier source modifiable sous Fusion 360

---

## Licence

Ce projet est open source. Libre à vous de le modifier et de l'adapter à vos besoins.
