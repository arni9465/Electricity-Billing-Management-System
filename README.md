# Electricity Billing Management System

## Overview
The Electricity Billing Management System is a menu-driven application developed using the C programming language. It calculates electricity bills based on the number of units consumed and stores customer billing records in a file.

## Features
- Add customer billing details.
- Calculate electricity bills using a slab-wise tariff system.
- Display all saved customer bills.
- Search for customer bills using Customer ID.
- Store billing records using file handling.

## Electricity Tariff

| Units Consumed | Rate |
|---|---:|
| 0–100 | ₹3/unit |
| 101–200 | ₹5/unit |
| 201–300 | ₹7/unit |
| Above 300 | ₹8/unit |

A fixed charge of ₹50 is added to each bill.

## Technologies Used
- C Programming
- Structures
- Functions
- Conditional Statements
- File Handling

## How to Run
1. Download or clone this repository.
2. Open `main.c` in a C compiler.
3. Compile and execute the program.
4. Follow the menu displayed on the screen.

## Project Structure
- `main.c` – Main source code.
- `bills.txt` – Customer billing records, created when bills are saved.

## Purpose
This project demonstrates the use of basic C programming concepts to develop a simple electricity billing and customer record management application.

## Status
Completed — initial implementation and functional testing.
