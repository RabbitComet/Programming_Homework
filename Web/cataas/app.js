const express = require("express");
require("dotenv").config();
const path = require("path");
const axios = require("axios");
const fs = require("fs");

const app = express();
const PORT = process.env.PORT;

app.use(express.static(__dirname));

app.get("/api/cat", async (req, res) => {
  const url = "https://cataas.com/cat";
  const cat = await axios.get(url, {
    responseType: "arraybuffer",
    headers: {
      Accept:
        "image/jpg,image/avif,image/webp,image/apng,image/svg+xml,image/*,*/*;q=0.8",
    },
  });
  fs.writeFileSync("cat.jpg", Buffer.from(cat.data));
  res.sendFile(path.join(__dirname,"cat.jpg"));
});

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "index.html"));
});

app.listen(PORT, () => {
  console.log(`Running on http://localhost:${PORT}`);
});
