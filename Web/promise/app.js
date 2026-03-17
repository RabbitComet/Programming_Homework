const fs = require("fs");
const { get } = require("http");
const rawData = fs.readFileSync("data.json", "utf-8");
const data = JSON.parse(rawData);

const getData = new Promise((resolve, reject) => {
  if (Math.random() < 0.5) {
    reject("Error: Could not fetch data.");
  } else {
    resolve(data);
  }
});

getData.then((result) => {
  console.log("Data fetched successfully:", result);
}).catch((error) => {
  console.error(error);
});
