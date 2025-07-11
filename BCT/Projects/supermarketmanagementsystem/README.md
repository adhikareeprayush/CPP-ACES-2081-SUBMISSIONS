# Supermarket Management System

## Introduction

The **Supermarket Management System** is a simple console-based application developed in C++ that helps manage the essential operations of a small supermarket or retail store. It provides functionality to maintain an inventory of products and allows cashiers to generate customer bills efficiently. The system supports product addition, editing, deletion, stock tracking, and billing with an easy-to-read receipt format.

## Purpose and Motivation

Managing inventory and billing manually in small retail shops can be error-prone and time-consuming. This project was created to automate and simplify:

- Keeping track of products, prices, and stock quantities.
- Allowing admin users to manage product details easily.
- Enabling cashiers to quickly generate customer bills while updating inventory automatically.
- Generating neat and formatted receipts that improve customer experience.

The system acts as a lightweight tool ideal for learning inventory management basics and console I/O handling in C++.

## Features

- **Product Management (Admin)**
  - Add new products with ID, name, price, and quantity.
  - Edit existing product details.
  - Delete products from inventory.
  - View current inventory with product details in a formatted table.

- **Billing (Cashier)**
  - View available products.
  - Generate bills by selecting products and specifying quantities.
  - Automatically updates inventory after billing.
  - Prints a neat, boxed receipt including product details, quantities, prices, and total.
  - Receipt includes a header with “ERC SUPERMARKET” and “BILL RECEIPT”.

- **Simple Menu System**
  - Separate menus for admin and cashier users.
  - Easy navigation with numbered options.
  - No login required (can be added later).

- **Persistent Storage**
  - Product data stored in a text file (`products.txt`) to maintain data between sessions.

## How to Use

### Setup

1. **Prepare product data file:**

   Create a `products.txt` file in the same directory as the executable. Each product should be on a separate line, fields separated by commas


2. **Compile the code:**

Using a C++ compiler, compile the source code. For example, using g++


3. **Run the program:**




### Main Menu

- Choose **1** for Admin Menu.
- Choose **2** for Cashier Menu.
- Choose **3** to exit.

### Admin Menu

- **Add Product:** Enter new product details.
- **Edit Product:** Modify existing product info by ID.
- **Delete Product:** Remove product by ID.
- **View Products:** See current inventory in table format.
- **Logout:** Return to main menu.

### Cashier Menu

- **View Products:** Displays available products with prices and quantities.
- **Generate Bill:** Select products and quantities to create a bill.
- **Logout:** Return to main menu.

### Generating Bills

1. Enter the Product ID.
2. Enter the quantity desired.
3. Repeat if more products are to be added.
4. The system will show a formatted bill receipt.
5. Inventory updates automatically.

## Design Overview

- **Data Structure:** Uses a `struct Product` to represent each product with fields for id, name, price, and quantity.
- **File Handling:** Reads and writes product data from/to a simple CSV text file.
- **Menus:** Implemented as loops with `switch` cases for options.
- **Billing:** Collects purchased products in a vector, calculates total, updates inventory, and prints receipt.
- **Receipt Formatting:** Uses fixed width and boxed ASCII styling for readability.

## Limitations and Future Improvements

- No user authentication — can be added to differentiate admin and cashier roles securely.
- No database — switching from text file to a database would improve scalability.
- No date/time on receipts — adding timestamps would be useful.
- No error handling on file operations.
- No GUI — can be upgraded to a graphical interface for better usability.
- Product search and filtering can be added.
- Reporting features (sales report, inventory report) could be implemented.

## Conclusion

This Supermarket Management System is a practical, beginner-friendly project that demonstrates fundamental programming concepts like file I/O, data structures, and formatted console output in C++. It can be used by small shops for basic inventory and billing or serve as a foundation to build more complex retail management software.

---


