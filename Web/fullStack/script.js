const form = document.getElementById('myForm');

form.addEventListener('submit', async event => {
    event.preventDefault(); 

    try{
        const formData = new FormData(form);
        const data = await fetch('/submit', {
            method: 'POST',
            body: formData
        });
    }
    catch(err){
        console.log(err);
    }

});