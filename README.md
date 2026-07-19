# 🛒 SmartCart – RFID Smart Billing System Using LPC2148 ARM7

<p align="center">

![Language](https://img.shields.io/badge/Language-C%20%7C%20Embedded%20C-blue) ![Microcontroller](https://img.shields.io/badge/Microcontroller-LPC2148-success) ![Architecture](https://img.shields.io/badge/Architecture-ARM7-green) ![Technology](https://img.shields.io/badge/Technology-RFID-orange) ![Communication](https://img.shields.io/badge/Communication-UART-blueviolet) ![Platform](https://img.shields.io/badge/Platform-Linux-lightgrey) ![Database](https://img.shields.io/badge/Database-CSV-informational) ![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</p>

---
# 📌 Project Description

The **SmartCart – RFID Smart Billing System** is an automated shopping and billing system developed using the **LPC2148 ARM7 microcontroller**, RFID technology, UART communication, and a Linux-based C application.

The system identifies products using RFID cards, manages the shopping cart, updates stock quantities, calculates the total bill, and supports cash and card-based payment processing.

The LPC2148 communicates with the Linux C application through UART, while CSV files are used to maintain product, cart, bank, and sales information.

---
# ✨ Key Features

- 🏷️ RFID-based product identification
- 🛒 Automatic product addition
- ➖ Product removal
- 📦 Stock quantity management
- 💰 Automatic bill calculation
- 👨‍💼 Manager mode
- 💵 Cash payment
- 💳 Card payment
- 🔐 PIN authentication
- 🏦 Bank balance verification
- 📡 UART communication
- 💾 CSV-based database management
- 🧾 Sales transaction storage

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
# 💻 Software Requirements

| Software | Purpose |
|----------|---------|
| Embedded C | LPC2148 firmware development |
| Keil μVision | Embedded code development |
| Flash Magic | Programming LPC2148 |
| Linux OS | Billing application execution |
| GCC Compiler | Compiling Linux C application |

---
# ⚙️ System Working Principle

The SmartCart system works through the following process:

1. The user selects the required operation.
2. The RFID card is scanned.
3. The LPC2148 receives the RFID information.
4. The RFID data is transmitted to the Linux application through UART.
5. The Linux application searches the corresponding database.
6. Product or bank information is retrieved.
7. The required operation is performed.
8. The database is updated.
9. The total bill is calculated.
10. The transaction is completed and stored.

---
# 📦 System Working Flow

<p align="center">
<img src="Images/System_Working_Flow.png" width="750">
</p>

---
# 🔄 Operating Modes

The SmartCart system uses external interrupts to select different operating modes.

| Interrupt | Operating Mode | Function |
|-----------|----------------|----------|
| EINT0 | Customer / Manager Mode | Add products or manage stock |
| EINT1 | Delete Mode | Remove products from the cart |
| EINT3 | Exit / Checkout Mode | Complete billing through cash or card payment |

# 🛒 EINT0 – Customer / Manager Mode

**EINT0** is used to enter the main operating modes of the SmartCart system.

When the user activates **EINT0**, the system provides two options:

- 🛒 Customer Mode
- 👨‍💼 Manager Mode

The user selects the required mode according to the operation to be performed.
## 🛒 Customer Mode

Customer Mode is used to add products to the shopping cart.

### Working Process

1. User selects Customer Mode through EINT0.
2. The product RFID card is scanned.
3. The LPC2148 reads the RFID number.
4. The RFID number is transmitted through UART.
5. The Linux application searches `stock.csv`.
6. Product information is retrieved.
7. The product is added to the cart.
8. The stock quantity is updated.
9. The total bill is calculated.
10. The updated cart information is stored.

## 👨‍💼 Manager Mode

Manager Mode is used for stock and product management.

The manager can:

- Add new products
- Update existing stock quantities
- Modify product information
- Maintain the product database

The manager selects Manager Mode through the EINT0 operating menu.

# ➖ EINT1 – Delete Mode

**EINT1** is used to remove products from the shopping cart.

### Working Process

1. User activates EINT1.
2. The system enters Delete Mode.
3. The product RFID card is scanned.
4. The RFID number is transmitted through UART.
5. The product is searched in the cart.
6. The selected product is removed.
7. The stock quantity is restored.
8. The product price is deducted from the total bill.
9. The cart and stock information are updated.

# 🚪 EINT2 – Exit / Checkout Mode

**EINT2** is used to exit the shopping process and complete the final billing operation.

When the user activates **EINT2**:

1. The current cart is displayed.
2. The final bill amount is calculated.
3. The system enters the payment selection.
4. The user selects a payment method:

   - 💵 Cash Payment
   - 💳 Card Payment

5. The selected payment is processed.
6. The transaction is completed.
7. The sales record is stored in `sales.csv`.

## 💵 Cash Payment

When Cash Payment is selected:

1. The final bill amount is calculated.
2. The customer selects Cash Payment.
3. The cash transaction is processed.
4. The transaction is completed.
5. The sales information is stored in `sales.csv`.

## 💳 Card Payment

When Card Payment is selected:

1. The customer scans the bank RFID card.
2. The card number is read.
3. The card information is transmitted through UART.
4. The system requests the ATM PIN.
5. The customer enters the PIN.
6. The PIN is validated.
7. The account balance is checked.
8. The bill amount is deducted.
9. The transaction is completed.
10. The sales record is stored in `sales.csv`.

The system provides up to **three PIN attempts** for authentication.

# 🔄 Complete System Flowchart

<p align="center">
<img src="Images/system_flowchart%20(2).png" width="750">
</p>
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



# 📦 Hardware Block Diagram

<p align="center">
<img src="Images/block_diagram.png" width="750">
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

# 📂 Database Files

The SmartCart Billing System maintains four CSV files for storing and updating data during system execution.

### 📦 stock.csv

Maintains product information.

| Field | Description |
|-------|-------------|
| Item | Product Name |
| RFID | Product RFID Number |
| Quantity | Available Stock |
| Price | Product Price |

### 🛒 cart.csv

Stores products currently added to the shopping cart.

| Field | Description |
|-------|-------------|
| Item | Product Name |
| RFID | Product RFID Number |
| Quantity | Selected Quantity |
| Price | Unit Price |
| Total | Product Total |

### 🏦 bank.csv

Stores customer bank account information.

| Field | Description |
|-------|-------------|
| Card ID | RFID ATM Card Number |
| Place | Branch Location |
| IFSC Code | Bank IFSC Code |
| Bank Name | Bank Name |
| Account Number | Customer Account Number |
| Balance | Available Balance |
| ATM PIN | Customer PIN |

### 🧾 sales.csv

Stores completed transaction details.

| Field | Description |
|-------|-------------|
| Bill Number | Unique Bill ID |
| Date | Transaction Date |
| Time | Transaction Time |
| Payment Mode | Cash / Card |
| Total Amount | Final Bill Amount |

---

# 📡 UART Communication

The LPC2148 communicates with the Linux-based billing application using UART.

Communication Process:

```
RFID Reader
      │
      ▼
LPC2148 ARM7
      │ UART
      ▼
Linux C Application
      │
      ▼
CSV Database Files
```

### UART Configuration

| Parameter | Value |
|-----------|-------|
| Device | /dev/ttyUSB0 |
| Baud Rate | 9600 bps |
| Data Bits | 8 |
| Stop Bits | 1 |
| Parity | None |

---

# 💳 Card Payment Process

When Card Payment is selected:

1. Customer scans ATM RFID card.
2. Card number and bill amount are sent to Linux.
3. Linux requests ATM PIN.
4. Customer enters PIN using keypad.
5. PIN is validated.
6. Account balance is checked.
7. Amount is deducted.
8. Transaction is completed.
9. Sales record is stored.

The customer is allowed **three PIN attempts**.

---

# 💵 Cash Payment Process

When Cash Payment is selected:

1. Customer selects Cash option.
2. Bill amount is displayed.
3. Customer pays the bill.
4. Transaction is completed.
5. Sales record is saved.

---

# 🔄 Overall System Flow

```
System Start
      │
      ▼
Scan RFID Card
      │
      ▼
Send Card Number via UART
      │
      ▼
Search Product Database
      │
      ▼
Retrieve Product Details
      │
      ▼
Add/Delete Product
      │
      ▼
Update Stock
      │
      ▼
Calculate Total Bill
      │
      ▼
Select Payment Mode
      │
      ▼
Cash / Card
      │
      ▼
Complete Transaction
      │
      ▼
Store Sales Information
```

---

# 🔒 System Features

- RFID-Based Product Identification
- Automatic Billing
- Real-Time Cart Management
- Product Addition
- Product Deletion
- Automatic Stock Update
- Manager Mode
- Cash Payment
- Card Payment
- PIN Authentication
- Bank Balance Verification
- UART Communication
- CSV Database Integration
- Sales Report Generation

---

# 📷 Project Demonstration

<p align="center">
<img src="Images/output1.png" width="700">
</p>

<p align="center">
<img src="Images/output2.png" width="450">
</p>

<p align="center">
<img src="Images/output3.png" width="450">
</p>

---

# 💻 Software Tools

- Embedded C
- Linux C Programming
- Keil μVision IDE
- Flash Magic
- GCC Compiler
- Linux Operating System

---

# 🔌 Hardware Used

- LPC2148 ARM7 Microcontroller
- RFID Reader
- RFID Cards
- 16×2 LCD
- 4×4 Matrix Keypad
- MAX232
- USB-to-UART Converter
- Power Supply

---

# 🚀 Future Enhancements

- QR Code Billing
- Mobile Payment Integration
- Cloud Database
- GSM Bill Notification
- Wi-Fi Connectivity
- IoT-Based Inventory Monitoring
- Mobile Shopping Application

---

# 🌍 Applications

- Smart Shopping Carts
- Supermarkets
- Shopping Malls
- Retail Stores
- Department Stores
- Automated Billing Systems
- Inventory Management

---

# 🎯 Advantages

- Faster Billing Process
- Eliminates Long Queues
- Accurate Billing
- Reduced Human Errors
- Easy Stock Management
- Secure Card Transactions
- User-Friendly Interface
- Low Maintenance Cost

---

# 👩‍💻 Developer

**Kotha Sangeetha**

**Bachelor of Technology**

**Electronics and Communication Engineering**

**2025 Graduate**

---

# 📜 License

This project is developed for **academic and educational purposes**.

Feel free to fork, modify, and improve the project.

---

# 🙏 Thank You

Thank you for visiting this project.
