const express = require('express');
const fs = require('fs');
const multer = require('multer');
require('dotenv').config();
const path = require('path');

const app = express();
const upload = multer();

const PORT = process.env.PORT;

app.use(express.static(__dirname));
app.use(upload.none());
app.use(express.json());

app.post('/submit', (req, res) => {
    const newData = req.body;

    const data = fs.readFileSync('data.json', 'utf-8');
    let jsonData;
    if(!data || data.trim() === ''){
        jsonData = { users: [] };
    }
    else{
        jsonData = JSON.parse(data);
    }
    jsonData.users.push(newData);

    fs.writeFile('data.json', JSON.stringify(jsonData,null,2), err => {
        if(err){
            console.log(err);
            res.status(500).send('Error saving data');
        }
        else{
            res.send('Data saved successfully');
        }
    });
});

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
});

app.get('/contact', (req, res) => {
    res.sendFile(path.join(__dirname, 'contact.html'));
});

app.listen(PORT, () => {
    console.log(`Running on http://localhost:${PORT}`);
});