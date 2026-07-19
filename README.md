# 🛒 Smart Cart – RFID Smart Billing System using LPC2148 ARM7
<p align="center">

![Language](https://img.shields.io/badge/Language-C%20%7C%20Embedded%20C-blue) 
![Microcontroller](https://img.shields.io/badge/Microcontroller-LPC2148-success) 
![Architecture](https://img.shields.io/badge/Architecture-ARM7-green) 
![Technology](https://img.shields.io/badge/Technology-RFID-orange) 
![Communication](https://img.shields.io/badge/Communication-UART-blueviolet) 
![Platform](https://img.shields.io/badge/Platform-Linux-lightgrey)
![Database](https://img.shields.io/badge/Database-CSV-informational)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</p>
## ⭐ Overview

An RFID-Based Smart Cart Billing System developed using the **LPC2148 ARM7 Microcontroller**, **EM4095 RFID Reader**, **UART Communication**, and a **Linux-based C application** to automate the shopping and billing process.

Unlike conventional billing systems, this project automatically identifies products using RFID technology, manages the shopping cart, calculates the total bill, updates stock information, and supports cash and card-based payment processing.

The system performs the following operations:

🛒 Product Identification

🏷️ RFID Tag Scanning

➕ Product Addition

➖ Product Removal

💰 Automatic Bill Calculation

📦 Stock Management

📟 LCD Display

💳 Card Payment

💵 Cash Payment

🧾 Sales Record Management

The EM4095 RFID Reader reads the unique RFID tag ID of each product. The LPC2148 receives the RFID data and communicates with a Linux-based C application through UART. The Linux application searches the product database, updates stock information, manages the cart, calculates the total bill, and processes the payment.

---

## 📷 Complete System Architecture

<img width="979" height="769" alt="image" src=" " />

---

## 🎯 Project Objectives

- Eliminate long billing queues
- Automate product identification using RFID
- Reduce manual billing errors
- Provide real-time bill calculation
- Maintain product and stock information
- Enable easy product addition and removal
- Support cash and card payments
- Provide secure PIN validation
- Maintain sales transaction records
- Improve the overall shopping experience

---

## 🔧 Hardware Components

| Hardware Component | Purpose |
|---|---|
| LPC2148 ARM7 Microcontroller | Controls RFID communication, LCD, keypad, and UART communication |
| EM4095 RFID Reader | Reads the unique RFID tag ID of each product |
| RFID Tags | Stores the unique identification number of each product |
| 16×2 LCD | Displays product information, cart details, and billing information |
| 4×4 Keypad | Used for user input and PIN entry |
| Switches | Used for selecting different system operations |
| MAX232 | Provides serial-level conversion where required |
| USB-to-UART Converter | Provides communication between the embedded system and Linux PC |
| Power Supply | Provides regulated power to the system |

---

## 🛒 System Working Flow

1. The system is initialized.
2. The LPC2148 waits for RFID card input.
3. The RFID Reader scans the RFID card.
4. The LPC2148 receives the RFID data.
5. The RFID number is sent to the Linux C application through UART.
6. The Linux application identifies the operation based on the received command.
7. The product or bank information is searched from the corresponding CSV file.
8. The required operation is performed.
9. The updated information is sent back through UART.
10. The LCD displays the required information.

<img width="731" height="1565" alt="image" src="https://github.com/user-attachments/assets/b03cb43e-d4a6-4f9e-a649-e9adbd07b62c" />

---

## 🧠 Operating Modes

The system supports multiple operating modes:

### 👤 Customer Mode

In customer mode:

- The product RFID card is scanned.
- The RFID number is sent to the Linux application.
- The product is searched in the stock database.
- Product information is retrieved.
- The product is added to the cart.
- The stock quantity is updated.
- The price is added to the total bill.

---

### ➖ Delete Mode

Delete mode is used to remove a product from the shopping cart.

The process includes:

- Scanning the product RFID card
- Searching for the product in the cart
- Removing the product
- Restoring the stock quantity
- Deducting the product price from the total bill
- Updating the cart information

---

### 👨‍💼 Manager Mode

Manager mode is used for managing stock information.

The manager can:

- Update existing product stock
- Add new products
- Modify product quantity
- Manage product information

---

### 💳 Card Transaction Mode

Card payment includes:

1. Scanning the bank card.
2. Identifying the card number.
3. Sending the card information and bill amount to the Linux application.
4. Requesting the ATM PIN.
5. Entering the PIN using the keypad.
6. Validating the PIN.
7. Checking the available bank balance.
8. Completing the transaction if validation is successful.
9. Updating the bank balance.
10. Saving the transaction details.

The system provides up to **three PIN attempts**. If all attempts fail, the card transaction is rejected.

---

### 💵 Cash Transaction Mode

For cash payment:

1. The total bill amount is calculated.
2. The customer selects cash payment.
3. The payment amount is processed.
4. The transaction is completed.
5. The sales information is saved.

---

## ➕ Product Addition

When a product RFID card is scanned in customer mode:

- Read the RFID Tag ID
- Send the RFID data through UART
- Search the product in the stock database
- Check product availability
- Retrieve product name and price
- Add the product to the cart
- Update the stock quantity
- Calculate the total bill
- Update the LCD display

---

## ➖ Product Removal

When a product is selected in delete mode:

- Read the RFID Tag ID
- Search for the product in the cart
- Remove the product from the cart
- Restore the stock quantity
- Deduct the product price from the total bill
- Update the cart
- Refresh the billing information

---

## 💾 Database Management

The Linux C application uses CSV files to manage the system data.

### 📦 stock.csv

Stores product information:

| Field | Description |
|---|---|
| Item | Product name |
| RFID | Unique RFID number |
| Quantity | Available stock quantity |
| Price | Product price |

Example:

```text
item,Rfid,quantity,price
Milk,12556450,4,100.00
Soap,12556451,10,50.00
Chips,12556452,20,10.00
