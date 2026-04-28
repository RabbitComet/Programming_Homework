const form = document.getElementById("signUpForm");


form.addEventListener('submit',async (e)=>{
    e.preventDefault();

    const data = new FormData(form);
    try{
        const response = await axios.post(`http://localhost:8080/signup`,data);
        console.log('Sign up successful:', response.data);
    } catch (error) {
        console.error('Error signing up:', error);
    }
});