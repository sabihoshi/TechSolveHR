# Employee Management System: Case Study 1

### College of Computer Studies

### CS Specialization 2 - Programming Tools and Techniques

---

## Table of Contents

- Employee Management System: Case Study 1
    - College of Computer Studies
    - CS Specialization 2 - Programming Tools and Techniques
    - Table of Contents
    - Introduction
        - Purpose
        - Scope
        - Definitions
    - Overall Description
        - Product Perspective \& Features
        - User Classes and Characteristics
        - Operating Environment \& Design Constraints
        - Assumptions and Dependencies
    - System Features and Requirements
        - Functional Requirements
            - User Record/Profile Editing
        - Non-Functional Requirements
        - System Models
            - Application Entity Relationship Diagram
    - Testing

---

## Introduction

### Purpose

TechSolve, as an IT services firm, has grown rapidly over the past few years. With its increasing scale, challenges
related to HR management have also scaled up, highlighting the inefficiencies of outdated management systems. The
primary aim of our Employee Management System is to replace manual processes, making HR tasks more streamlined,
efficient, and error-free.

### Scope

The Employee Management System is a lightweight CLI application, built primarily using C++. It covers essential HR
processes like onboarding, resource management, and attendance tracking. Key features include User Profile Editing,
Leave Application, Admin Control, Attendance, and Resource Access.

### Definitions
- HR: Human Resources. This department manages various aspects related to employees, including recruitment, training,
performance evaluations, and payroll.
- TIN#: Tax Identification Number. It's an identification number used for tax purposes.
- PhilHealth: The Philippine Health Insurance Corporation. It's a government agency that ensures the health of the
Filipino people.
- SSS: Social Security System. A social insurance program in the Philippines for workers in the private, professional, and
informal sectors.
- JSON: JavaScript Object Notation. A lightweight data-interchange format that's easy for humans to read and write and
easy for machines to parse and generate.
- nlohmann (Niels Lohmann): Refers to a popular open-source JSON library for C++ developed by Niels Lohmann.
- Boolinq: A library in C++ that brings SQL-like query abilities.
- SQL: Structured Query Language. It's a domain-specific language used in programming for managing and querying data held
in a relational database management system.
- Entity Relationship Diagram (ERD): A graphical representation of the logical structure of a database. It shows the
relationships between entities (tables).
- Performance Appraisal: A regular review of an employee's job performance and overall contribution to the company.
- Onboarding: The process of integrating a new employee into the organization and its culture.

Business Performance Management: The process of analyzing business performance and taking steps to improve it.
---

## Overall Description

### Product Perspective & Features

The Employee Management System integrates seamlessly with TechSolve's existing IT infrastructure, offering a
comprehensive suite of tools to support HR functions. Key features include:

- **Employee Onboarding**: Simplifies the process of integrating new hires into the system.
- **Attendance Tracking**: Automates the logging of daily attendance, reducing manual errors.
- **Resource Management**: Provides a centralized location for all company resources, ensuring everyone has access to
  the latest and most accurate data.
- **Performance Evaluation**: Offers tools for managers to evaluate employee performance, helping identify areas of
  improvement.

### User Classes and Characteristics

The system caters to two primary user groups:

1. **Administrators**: Have full control over the system, can add, edit, or delete user profiles, manage resources, and
   view system-wide reports.
2. **Employees**: Can edit their profiles, apply for leaves, access company resources, and view their attendance and
   performance reports.

### Operating Environment & Design Constraints

The system is designed exclusively for Windows environments (Windows 10 and 11). It's optimized for a CLI interface,
given the preference for lightweight and fast operations within TechSolve. It relies on a shared database, requiring
consistent network connectivity.

### Assumptions and Dependencies

A few critical assumptions underpinning the system include:

- All users have basic familiarity with CLI interfaces.
- The shared database is consistently available and regularly backed up.
- The system's functionalities are regularly updated to accommodate evolving company needs.

Dependencies include:

- Microsoft Visual C++ for core functionalities.
- nlohmann's JSON library for data management.
- Boolinq for implementing SQL-like queries.

---

## System Features and Requirements

### Functional Requirements

#### User Record/Profile Editing

- **Inputs**: User profile data.
- **Processing**: Validation, serialization, and updating.
- **Outputs**: Confirmation message and updated profile.

### Non-Functional Requirements

- **Performance**: Should respond within seconds.
- **Reliability**: Downtime should not exceed 0.1% annually.
- **Usability**: Training for using the system shouldn't take more than 2 hours for any user.
- **Scalability**: Should accommodate up to 10,000 users without any degradation in performance.

### System Models

#### Application Entity Relationship Diagram

This diagram showcases relationships between various entities like Users, Admins, Resources, etc., giving a clear
picture of data flow and hierarchies.

---

## Testing

Testing involved unit tests and running the code manually, ensuring all functionalities work as expected.
