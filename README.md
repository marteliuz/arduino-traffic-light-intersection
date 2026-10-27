# 🚦 Arduino Traffic Light Intersection System

Un sistema de control de tráfico para un cruce de calles de una vía con semáforos vehiculares y pasos peatonales independientes, desarrollado con **Arduino Uno**.

El proyecto implementa un control de tiempos por fases, transición con parpadeo de precaución para peatones, pausa de seguridad entre cambios de vía y monitoreo en tiempo real por puerto serial.

---

## 🛠️ Componentes y Hardware

* **Controlador:** Arduino Uno R3
* **Protoboard:** 830 puntos
* **Semáforos Vehiculares:** 6x LEDs (2x Rojo, 2x Amarillo, 2x Verde)
* **Semáforos Peatonales:** 4x LEDs (2x Rojo, 2x Verde)
* **Resistencias:** $220\,\Omega$ / $330\,\Omega$ por línea de señal
* **Estructura:** Postes con cátodo común (tierra compartida por módulo)

---

## 💻 Diagrama de Pines (Pinout)

### Calle A
| Componente | Pin Arduino |
| :--- | :--- |
| **Verde Vehicular (V1)** | Pin 3 |
| **Amarillo Vehicular (AM1)** | Pin 4 |
| **Rojo Vehicular (R1)** | Pin 5 |
| **Verde Peatonal (PV1)** | Pin 6 |
| **Rojo Peatonal (PR1)** | Pin 7 |

### Calle B
| Componente | Pin Arduino |
| :--- | :--- |
| **Verde Vehicular (V2)** | Pin 8 |
| **Amarillo Vehicular (AM2)** | Pin 9 |
| **Rojo Vehicular (R2)** | Pin 10 |
| **Verde Peatonal (PV2)** | Pin 11 |
| **Rojo Peatonal (PR2)** | Pin 12 |

---

## ⚙️ Lógica de Funcionamiento

1. **Fase 1 (Paso Calle A):**
   * Vehicular A en VERDE (6s), Peatonal A en ROJO.
   * Vehicular B en ROJO, Peatonal B en VERDE.
   * Transición: Amarillo en Calle A y parpadeo de aviso en Peatonal B (3 ciclos).
   * Pausa de seguridad: Todos en ROJO (1s).

2. **Fase 2 (Paso Calle B):**
   * Vehicular B en VERDE (6s), Peatonal B en ROJO.
   * Vehicular A en ROJO, Peatonal A en VERDE.
   * Transición: Amarillo en Calle B y parpadeo de aviso en Peatonal A (3 ciclos).
   * Pausa de seguridad: Todos en ROJO (1s).

3. **Monitor Serial:**
   * Comunicación a `9600 baudios` reportando en tiempo real el cambio de estados.

---

## 🚀 Próximas Mejoras (Roadmap)

- [ ] Integración de zumbador (piezo buzzer) para señal acústica durante el parpadeo peatonal.
- [ ] Incorporación de botón de solicitud de paso para peatones.

---

## 📄 Licencia

Este proyecto está bajo la Licencia MIT - siéntete libre de utilizarlo y modificarlo.
