# ESP8266 IoT Ventilator with Health Monitoring

This project presents an ESP8266-based IoT ventilator with remote control capabilities via the Blynk app. It's equipped with features like high heart rate alert and real-time blood oxygen level monitoring, making it suitable for emergency situations where conventional oxygen cylinders may not be available.

*Note:* (Refer reference images .zip if images are not visible)

![WhatsApp Image 2024-03-24 at 19 22 33](https://github.com/keshavmarian/ESP8266-IoT-Ventilator-/assets/88151753/3d9a505f-ae7a-4f16-b923-fe911aa45b93)

## Features

- Remote on/off control via Blynk app.
- High heart rate alert functionality.
- Real-time monitoring of blood oxygen levels.
- Ventilation speed control with three modes: low, mid, and high.
- Utilizes components such as potentiometer, L298N motor driver, 60 RPM single shaft 12V motor, adapter, 12V power supply, breadboard, connecting wires, jumpers, MAX30100 heart rate sensor, 16x2 LCD, I2C converter, and an adult-sized Ambu bag.

## Medical Application

This IoT ventilator serves as a supportive device during emergencies when traditional oxygen cylinders are not accessible. It's crucial to understand that this device does not replace professional medical equipment and should only be used when no other options are available. Here's how it works:

### Overview

1. **Remote Control**: The ventilator can be remotely controlled using the Blynk app installed on a smartphone. Users can switch it on or off based on the patient's needs.

2. **High Heart Rate Alert**: The system is equipped with a high heart rate alert feature. If the patient's heart rate exceeds a predefined threshold (e.g., 110 bpm), the system triggers an alert, notifying the caretaker about the critical condition.

3. **Blood Oxygen Monitoring**: Real-time monitoring of blood oxygen levels is crucial for assessing the patient's respiratory health. The MAX30100 heart rate sensor continuously measures the oxygen saturation level in the patient's blood, providing valuable feedback to the caretaker.

4. **Ventilation Control**: The ventilator controls the airflow to the patient using a 60 RPM single shaft 12V motor driven by the L298N motor driver. The motor's speed can be adjusted based on the patient's requirements, ensuring adequate ventilation. The ventilation speed can be set to low, mid, or high using a potentiometer.

### Working Principle

Upon powering on the device, the patient is instructed to place their finger on the MAX30100 heart rate sensor, which is integrated into the system. This sensor utilizes photoplethysmography (PPG) to detect changes in blood volume in the microvascular bed of tissue. By illuminating the skin with LED light, the sensor captures the amount of light absorbed by the blood, allowing it to determine the heart rate and blood oxygen saturation levels of the patient in real-time.

The collected data is then transmitted wirelessly to the Blynk app installed on a smartphone. Through the Blynk platform, caregivers and medical professionals can remotely monitor the patient's vital signs, including heart rate and blood oxygen levels, ensuring timely intervention if any abnormalities are detected. Additionally, the same data is simultaneously displayed on the LCD screen of the device, providing immediate feedback to those in proximity to the patient.

To enable seamless connectivity and data transmission, the device is configured to automatically connect to a pre-defined Wi-Fi network upon startup. This eliminates the need for manual intervention and ensures continuous monitoring and control capabilities.

The ventilation support is provided through the pumping action of an Ambu bag, a self-inflating manual resuscitator commonly used in medical emergencies. The Ambu bag is connected to an arm (rack and pinion setup), which is driven by a motor controlled by the system. The speed of the motor, and consequently the frequency of pumps delivered by the Ambu bag, can be adjusted using a potentiometer.

The potentiometer offers three levels of control: low, mid, and high. By rotating the potentiometer knob, the user can vary the resistance, thereby altering the speed of the motor and adjusting the ventilation rate accordingly. This dynamic control mechanism allows caregivers to tailor the ventilation support to the specific needs of the patient, ensuring optimal respiratory assistance.

In summary, the device operates as an automated ventilator system, combining real-time health monitoring with adjustable ventilation support. By leveraging modern IoT technology, it offers a flexible and user-friendly solution for emergency medical situations, empowering caregivers to deliver timely and personalized care to patients in need.


### Medical Instructions

- **Emergency Use Only**: This IoT ventilator is designed for emergency situations only. It should not be used as a primary medical device and must be operated under the supervision of trained medical personnel.

- **Monitoring**: Regularly monitor the patient's vital signs, including heart rate and blood oxygen levels, while using the ventilator. Any significant deviations from normal readings should be addressed immediately.

- **Backup Power**: Ensure that the ventilator has a reliable power source, preferably a backup battery or generator, to prevent interruptions in case of power outages.

- **Professional Assistance**: Seek professional medical assistance as soon as possible. This ventilator is a temporary solution and does not replace comprehensive medical care provided by healthcare professionals.

- **Safety Precautions**: Follow all safety precautions and guidelines provided with the components used in this project. Improper assembly or operation may lead to injury or worsen the patient's condition.

## Circuit Diagram

*Note:* (Refer reference images .zip if images are not visible)
![WhatsApp Image 2024-03-24 at 18 06 19](https://github.com/keshavmarian/ESP8266-IoT-Ventilator-/assets/88151753/70f01f57-3037-4196-aaa1-de1e9128850b)

## Block Diagram 

*Note:* (Refer reference images .zip if images are not visible)
<img width="863" alt="Screenshot 2024-03-24 at 6 20 55 PM" src="https://github.com/keshavmarian/ESP8266-IoT-Ventilator-/assets/88151753/9fcb9af6-e5df-4020-abe4-8af5aa58c69d">

## BLYNK 
*Note:* (Refer reference images .zip if images are not visible)
![WhatsApp Image 2024-03-24 at 19 19 01](https://github.com/keshavmarian/ESP8266-IoT-Ventilator-/assets/88151753/b4b2f62e-013e-45f0-8973-d5b9a04b2ac6)
![WhatsApp Image 2024-03-24 at 19 19 23](https://github.com/keshavmarian/ESP8266-IoT-Ventilator-/assets/88151753/d0a1f5a7-9487-4696-9993-4b898d4fe17c)


## Disclaimer

This IoT ventilator is intended for educational and emergency use only. It should not be used as a substitute for professional medical equipment or treatment. Use it responsibly and always prioritize the patient's safety and well-being.

**Note:** Always consult with a medical professional or healthcare provider before using any medical device, including this IoT ventilator.

