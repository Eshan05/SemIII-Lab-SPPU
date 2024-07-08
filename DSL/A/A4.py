"""
4. WAPP that computes the net amount of a bank account based a transaction log from console input. The transaction log format is shown as following: D 100 W 200 (Withdrawal is not allowed if balance is going negative. Write functions for withdraw and deposit) D means deposit while W means withdrawal. Suppose the following input is supplied to the program: D 300, D 300, W 200, D 100 Then output should be 500
"""

def deposit(balance, amount):
    """
    Deposits the given amount to the current balance.
    
    Args:
        balance (float): The current balance of the bank account.
        amount (float): The amount to be deposited.
    
    Returns:
        float: The updated balance after the deposit.
    """
    return balance + amount

def withdraw(balance, amount):
    """
    Withdraws the given amount from the current balance, if the balance is sufficient.
    
    Args:
        balance (float): The current balance of the bank account.
        amount (float): The amount to be withdrawn.
    
    Returns:
        float: The updated balance after the withdrawal, or the current balance if the withdrawal is not allowed.
    """
    if balance >= amount:
        return balance - amount
    else:
        return balance

# Read the transaction log from console input
transactions = input("Enter the transaction log (e.g., D 300, D 300, W 200, D 100): ").split(", ")

# Initialize the balance
balance = 0

# Process the transactions
for transaction in transactions:
    operation, amount = transaction.split()
    amount = float(amount)
    if operation == "D":
        balance = deposit(balance, amount)
    elif operation == "W":
        balance = withdraw(balance, amount)

# Print the final balance
print(f"The net amount in the bank account is: {balance}")
