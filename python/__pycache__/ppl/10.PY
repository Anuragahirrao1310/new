
class BankAccount:
    def __init__(self, account_number, account_holder_name, balance, pin_number):
        self.account_number = account_number
        self.account_holder_name = account_holder_name
        self.balance = balance
        self.pin_number = pin_number

    def check_balance(self):
        return self.balance

    def withdraw_amount(self, amount):
        if self.balance >= amount:
            self.balance -= amount
            return amount
        else:
            return "Insufficient funds"

    def deposit_amount(self, amount):
        self.balance += amount
        return amount

    def mini_statement(self):
        # Generate mini statement
        statement = "Mini Statement:\n" \
                    f"Account Number: {self.account_number}\n" \
                    f"Account Holder Name: {self.account_holder_name}\n" \
                    f"Balance: {self.balance}"
        return statement

    def change_pin(self, new_pin):
        self.pin_number = new_pin
        return "PIN changed successfully"


class ATM:
    def __init__(self):
        self.bank_account = None

    def authenticate_account(self):
        account_number = input("Enter account number: ")
        pin_number = input("Enter PIN: ")
        # Assume account details are stored in a dictionary or database
        account_details = {
            "1234567890": {"account_holder_name": "John Doe", "balance": 5000, "pin_number": "1234"}
            # Add more account details here
        }

        if account_number in account_details and account_details[account_number]["pin_number"] == pin_number:
            account_info = account_details[account_number]
            self.bank_account = BankAccount(account_number, account_info["account_holder_name"],
                                            account_info["balance"], account_info["pin_number"])
            print("Authentication successful.")
        else:
            print("Invalid account number or PIN. Authentication failed.")

    def display_menu(self):
        print("Menu:")
        print("1. Check Balance")
        print("2. Withdraw Amount")
        print("3. Deposit Amount")
        print("4. Mini Statement")
        print("5. Change PIN")
        print("6. Exit")

    def execute_operation(self, choice):
        if choice == 1:
            balance = self.bank_account.check_balance()
            print(f"Balance: {balance}")
        elif choice == 2:
            amount = float(input("Enter amount to withdraw: "))
            withdrawn_amount = self.bank_account.withdraw_amount(amount)
            print(f"Withdrawn amount: {withdrawn_amount}")
        elif choice == 3:
            amount = float(input("Enter amount to deposit: "))
            deposited_amount = self.bank_account.deposit_amount(amount)
            print(f"Deposited amount: {deposited_amount}")
        elif choice == 4:
            statement = self.bank_account.mini_statement()
            print(statement)
        elif choice == 5:
            new_pin = input("Enter new PIN: ")
            result = self.bank_account.change_pin(new_pin)
            print(result)
        elif choice == 6:
            print("Exiting...")
            exit()
        else:
            print("Invalid choice. Please try again.")

    def run(self):
        self.authenticate_account()

        if self.bank_account:
            while True:
                self.display_menu()
                choice = int(input("Enter your choice: "))
                self.execute_operation(choice)


# Main program
atm = ATM()
atm.run()




#**********************************************************************/

