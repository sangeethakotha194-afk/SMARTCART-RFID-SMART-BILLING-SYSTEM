# 🛒 SmartCart – RFID Smart Billing System Using LPC2148 ARM7

<p align="center">

![Language](https://img.shields.io/badge/Language-C%20%7C%20Embedded%20C-blue) ![Controller](https://img.shields.io/badge/Microcontroller-LPC2148-success) ![Architecture](https://img.shields.io/badge/Architecture-ARM7-green) ![Technology](https://img.shields.io/badge/Technology-RFID-orange) ![Communication](https://img.shields.io/badge/Communication-UART-blueviolet) ![Platform](https://img.shields.io/badge/Platform-Linux-lightgrey) ![Database](https://img.shields.io/badge/Database-CSV-informational) ![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</p>

---

# 📌 Project Description

The **SmartCart – RFID Smart Billing System** is an embedded automation project developed using the **LPC2148 ARM7 microcontroller**, RFID technology, UART communication, and a Linux-based C application.

The system automates the shopping and billing process by identifying products using RFID cards. The LPC2148 communicates with a Linux C application through UART. The Linux application manages the product stock, shopping cart, bank information, billing, and sales transaction data.

The system supports:

- 🏷️ RFID-based product identification
- 🛒 Product addition
- ➖ Product deletion
- 📦 Stock management
- 💰 Automatic bill calculation
- 👨‍💼 Manager mode
- 💵 Cash payment
- 💳 Card payment
- 🔐 PIN validation
- 🏦 Bank balance verification
- 🧾 Sales record management

---

# 🎯 Objectives

- Automate the traditional billing process
- Identify products using RFID technology
- Reduce manual billing operations
- Add products to the shopping cart
- Remove products from the shopping cart
- Automatically calculate the total bill
- Manage product stock information
- Support cash and card payments
- Validate ATM PIN securely
- Maintain bank account information
- Store completed sales transactions

---

# ✨ Project Highlights

- LPC2148 ARM7-based embedded system
- RFID-based product identification
- UART communication between embedded system and Linux application
- Product stock management
- Shopping cart management
- Manager stock update facility
- Automatic billing calculation
- Cash payment support
- Card payment support
- ATM PIN validation
- Three-attempt PIN verification
- Bank balance checking
- Database integration using CSV files
- Sales transaction management

---

# 🏗️ System Architecture

<p align="center">
<img src="Images/system_architecture.png" width="800">
</p>

---

# 🔧 Hardware Requirements

| Component | Purpose |
|------------|---------|
| LPC2148 ARM7 | Main controller |
| RFID Reader | Reads RFID card numbers |
| RFID Cards | Used for product and bank card identification |
| 16×2 LCD | Displays system and billing information |
| 4×4 Keypad | Used for user input and PIN entry |
| Switches | Used for Entry, Delete, and Exit operations |
| MAX232 | Serial communication level conversion |
| USB-to-UART Converter | Communication with Linux PC |
| Power Supply | Provides power to the system |

---

# 📦 Hardware Block Diagram

<p align="center">
<img src="Images/block_diagram.png" width="750">
</p>

---

# 📦 System Working Flow

<p align="center">
<img src="Images/System_Working_Flow.png" width="750">
</p>

---

# 🔄 System Operation

The system initially displays the project name and waits for the user to select an operation.

The user can perform:

- 🛒 Entry / Add Product
- ➖ Delete Product
- 🚪 Exit / Checkout

---

# 🛒 Entry Mode – Add Product

When the user selects the Entry operation:

1. The system waits for an RFID card.
2. The RFID reader reads the card number.
3. The LPC2148 receives the RFID data.
4. The card number is sent to the Linux application through UART.
5. The product is searched in the stock database.
6. Product information and price are retrieved.
7. The available quantity is updated.
8. The product is added to the shopping cart.
9. The product cost is added to the total bill.
10. The updated information is displayed.

---

# ➖ Delete Mode – Remove Product

Delete mode is used to remove a product from the shopping cart.

The process includes:

- Scan the product RFID card
- Send the card number through UART
- Search for the product
- Remove the product from the cart
- Restore the product quantity in stock
- Deduct the product price from the total bill
- Update the billing information

---

# 👨‍💼 Manager Mode

Manager mode is used to update the product stock database.

The manager can:

- Add new stock information
- Update existing product quantity
- Manage product information
- Update product details in the database

The manager RFID card is identified by the system and the information is sent to the Linux application for stock management.

---

# 💾 Database Management

The Linux C application uses database files to store the system information.

## 📦 stock.csv

Stores product stock information.

| Field | Description |
|-------|-------------|
| Item | Product name |
| RFID | Unique product RFID number |
| Quantity | Available product quantity |
| Price | Product price |

Example:

```text
item,Rfid,quantity,price
Milk,12556450,4,100.00
Soap,12556451,10,50.00
Chips,12556452,20,10.00
