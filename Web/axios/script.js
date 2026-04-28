const myForm = document.getElementById("myForm");

myForm.addEventListener("submit", async (event) => {
  event.preventDefault();
  const formData = new FormData(myForm);

    try{
        axios.post("http://localhost:3000/register", formData);

        alert("Registration successful!");
    }
    catch(error){
        console.error("Error:", error);
    }
});