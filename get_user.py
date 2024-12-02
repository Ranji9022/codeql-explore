import sqlite3

class Database:
    def __init__(self, db_file):
        self.conn = sqlite3.connect(db_file)
        self.cursor = self.conn.cursor()

    def query_user(self, username):
        query = "SELECT * FROM users WHERE username = '" + username + "'"
        self.cursor.execute(query)
        return self.cursor.fetchall()

if __name__ == "__main__":
    db = Database("mydatabase.db")
    username = input("Enter username: ")
    results = db.query_user(username)
    print(results)
