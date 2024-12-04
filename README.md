# Teensy MIDI Relay

A project that uses a Teensy microcontroller to control relays via MIDI commands. This project is perfect for musicians, lighting technicians, and DIY enthusiasts who want to integrate MIDI-controlled relays into their setups.

## Features

- **MIDI Integration**: Controls relays using MIDI commands for seamless integration with musical instruments and software.
- **Relay Control**: Supports multiple relays for custom lighting, effects, or any other relay-based applications.
- **Customizable**: Easily modify the code to suit your MIDI and relay requirements.
- **Real-Time Control**: Low-latency response for live performances.

## Components Required

- **Teensy Microcontroller** (e.g., Teensy 3.2, Teensy 4.0)
- **Relay Module** (Single or multi-channel relay board)
- **MIDI Interface** (Optional if using USB MIDI)
- **Power Supply** (5V for the Teensy and relays)
- Connecting wires and a breadboard (optional for prototyping)

## Installation

### Set Up Arduino IDE

1. Install the [Teensyduino Add-On](https://www.pjrc.com/teensy/teensyduino.html) for the Arduino IDE.
2. Install any required libraries, including:
   - `MIDI Library` for MIDI communication.

### Configure the Code

1. Open `Teensy-MIDI-Relay.ino` in the Arduino IDE.
2. Set up the MIDI channel and note/command mapping to relay outputs.
3. Assign the GPIO pins for each relay.

### Upload the Code

1. Connect your Teensy microcontroller to your computer via USB.
2. Select the correct Teensy board and port in the Arduino IDE.
3. Upload the code.

## Configuration

### MIDI Setup

1. Configure your MIDI hardware or software to send commands to the Teensy.
2. Ensure the Teensy is recognized as a MIDI device (for USB MIDI).
3. Map MIDI notes or control change (CC) messages to relay functions.

### Relay Connections

1. Connect the relay module to the Teensy GPIO pins.
2. Ensure proper voltage and current requirements for the relay module are met.

## Usage

1. Send MIDI commands (notes or CC messages) from your MIDI controller or software.
2. Relays will toggle or activate based on the MIDI commands received.

## Example

- MIDI Note `C4` (MIDI Note 60) activates Relay 1.
- MIDI CC message `#20` with a value of 127 toggles Relay 2.

## Pinout Diagram

| GPIO Pin | Function        |
|----------|-----------------|
| Pin X    | Relay 1 Control |
| Pin Y    | Relay 2 Control |
| Pin Z    | Relay 3 Control |

*(Replace X, Y, Z with the actual GPIO pins used in your project.)*

## Troubleshooting

- **No MIDI Response**: Verify that your Teensy is recognized as a MIDI device and the MIDI channel matches your configuration.
- **Relays Not Activating**: Check the wiring and GPIO pin assignments.
- **Unexpected Behavior**: Ensure that MIDI messages are correctly mapped in the code.

## License

This project is licensed under the [MIT License](LICENSE).

## Contributions

Contributions are welcome! Feel free to open an issue or submit a pull request.

## Support

If you have questions or need help, reach out via the [GitHub Issues](https://github.com/yourusername/Teensy-MIDI-Relay/issues) page.
