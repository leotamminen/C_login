# Caesar Cipher Login System

This C program is a simple login system using the Caesar cipher for encryption and decryption. It reads username and password from a CSV file ```passwords.csv```.

One line of the ```passwords.csv``` contains username and password in the following form: ```username,password```. If the login is successful, user are granted access to view the contents of a secret file ```secret.txt``` after decrypting it using the Caesar cipher.

## Features:

- **User Login:** User is prompted to enter username and password. Password input is masked for security. Login is successful only if both match. After invalid login attempt, user can try again.
  
- **Caesar Cipher Encryption/Decryption:** The program uses a Caesar cipher to encrypt and decrypt sensitive information, ensuring a basic level of security.

- **Secret File Access:** If the login is successful, user can view decrypted content of the file ```secret.txt```, which is otherwise difficult to read.

## How to Use:

1. **Compile:** Compile the program using a C compiler.

    ```bash
    gcc main.c -o password_hide
    ```

2. **Run:** Execute the compiled program.

    ```bash
    ./password_hide
    ```

3. **Login:** Enter your username and password when prompted.

4. **Secret Access:** Upon successful login, view the decrypted contents of the secret file.