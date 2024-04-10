from flask import Flask, render_template, redirect, request, flash
import sqlite3
import os 

app = Flask(__name__)
app.secret_key = 'nelcode'

# Connect to SQLite database
conn = sqlite3.connect('form_data.db', check_same_thread=False)
c = conn.cursor()

# Create table
c.execute('''
    CREATE TABLE IF NOT EXISTS form_data
    (name TEXT, email TEXT, message TEXT)
''')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/send', methods=['GET', 'POST'])
def send():
    if request.method == 'POST':
        name = request.form["name"]
        email = request.form["email"]
        message = request.form["message"]

        # Connect to SQLite database
        conn = sqlite3.connect('form_data.db', check_same_thread=False)
        c = conn.cursor()

        # Insert data into database
        c.execute("INSERT INTO form_data VALUES (?, ?, ?)", (name, email, message))
        conn.commit()

        # Close the connection
        conn.close()

        flash('Message sent successfully!') 
    return redirect('/')


if __name__=='__main__': 
    app.run(debug=True)

# Close the connection
conn.close()
