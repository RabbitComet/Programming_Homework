const express = require("express");
const path = require("path");
const app = express();
const port = 8080;

app.use("/images", express.static(path.join(__dirname, "public/images")));

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "public", "index.html"));
});

app.get("/about", (req, res) => {
  res.sendFile(path.join(__dirname, "public", "about.html"));
});

app.get("/contact", (req, res) => {
  res.sendFile(path.join(__dirname, "public", "contact.html"));
});

app.listen(port, function () {
  console.log(`Example app listening at http://localhost:${port}`);
});

const user = {
  name: "John Doe",
  surname: "Smith",
  middlename:" ",
  age: 30,
  
  fullname: function () {
    return `${this.name}${this.middlename}${this.surname}`;
  },

  validateName: function(name) {
    if(!name){
      console.log("Name cannot be empty");
      return false;
    }

    

    const regex = /^(?=.*\p{L})[\p{L}']{1,50}([\s'-]\p{L}{1,50}){1,5}$/u;
    if (!regex.test(name)) {
      console.log("Name must be between 1 and 50 characters, and can include letters, spaces, hyphens, and apostrophes.");
      return false;
    }
    return true;
  },


  set setName(name) {
    name = name.trim();

    if(this.validateName(name)){
      name  = name.split(" ");
      this.name = "";
      this.middlename = "";
      this.surname = ""; 
      switch (name.length) {
        case 1:
          this.name = name[0];
          break;
        case 2:
          this.name = name[0] + " ";
          this.surname = name[1];
          break;
        default:
          this.name = name[0] + " ";
          for (let i = 1; i < name.length - 1; i++) {
            this.middlename += name[i] + " ";
          }
          this.surname = name[name.length - 1];
          break;
    }
    console.log("Name Changed!");
    }

  }

}
console.log(user.fullname());

user.setName = "";
console.log(user.fullname());

user.setName = "   ";
console.log(user.fullname());

user.setName = "  ----- ";
console.log(user.fullname());

user.setName = "sandal mandal s-sd";
console.log(user.fullname());

user.setName = "martin'";
console.log(user.fullname());

user.setName = "атом атомов атомович";
console.log(user.fullname());

user.setName = "վազգեն վազգենյան վազգենի";
console.log(user.fullname());

user.setName = "demarcus saint-lewis";
console.log(user.fullname());

user.setName = "tyrone de'santis";
console.log(user.fullname());

user.setName = "demarcus -saint-lewis";
console.log(user.fullname());

user.setName = "o'brien";
console.log(user.fullname());