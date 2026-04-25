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
