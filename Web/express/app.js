const express = require('express');
const path = require('path');
const app = express();
const port = 8080;

app.use('/images', express.static(path.join(__dirname, "public/images")));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

app.listen(port, function(){
  console.log(`Example app listening at http://localhost:${port}`);
});