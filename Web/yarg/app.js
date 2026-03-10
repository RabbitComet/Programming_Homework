require("dotenv").config();
const myModule = require("./MyModule");
const yargsFactory = require("yargs/yargs");
const { hideBin } = require("yargs/helpers");
const express = require("express");
const app = express();
let emailList = ["JohnsEmail"];
const argv = yargsFactory(hideBin(process.argv))
  .command(
    "add",
    "Add Email.",
    {
      email: {
        describe: "Add an email address",
        alias: "e",
        type: "string",
        demandOption: true,
      },
    },
    (argv) => {
      emailList = myModule.addEmail(argv.email, emailList);
      console.log("Current email list:", emailList);
    },
  )
  .command(
    "remove",
    "Remove Email.",
    {
      email: {
        describe: "Email address to remove",
        alias: "e",
        type: "string",
        demandOption: true,
      },
    },
    (argv) => {
      emailList = myModule.removeEmail(argv.email, emailList);
      console.log("Current email list:", emailList);
    },
  )
  .help()
  .parse();

app.listen(process.env.PORT, () => {
  console.log(`Server is running on port ${process.env.PORT}`);
});

// console.log("Command-line arguments:", argv);
