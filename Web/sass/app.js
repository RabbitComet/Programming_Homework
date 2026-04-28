const express = require("express");
require("dotenv").config();
const fs = require("fs");
const path = require("path");
const usersFilePath = path.join(__dirname, "users.json");
const validator = require("./auth/validator.js");
const multer = require("multer");
const PORT = process.env.PORT || 8080;
const app = express();
const upload = multer();
app.use(express.static(__dirname));

app.post("/signup", upload.none(), validator, (req, res) => {
  const data = req.body;
  const users = fs.readFileSync(usersFilePath, "utf-8");
  let newUsers = { emails: [], ages: [], passwords: [] };
  if (users && users.length != 0) {
    newUsers = JSON.parse(users);
  }

  for (let key in data) {
    newUsers[key + "s"].push(data[key]);
  }

  fs.writeFile(usersFilePath, JSON.stringify(newUsers, null, 2), (err) => {
    if (err) {
      console.error("Error writing to file:", err);
      return res.status(500).send("Internal Server Error");
    }
    res.status(200).send("User registered successfully");
  });
});

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "index.html"));
});

app.listen(PORT, () => {
  console.log(`live at http://localhost:${PORT}`);
});
