function ageValidator(age) {
    const errors = [];
   if(!age){
    errors.push("Age is required");
   }
   else if(isNaN(age)){
    errors.push("Age must be a number");
   }
    else if(age < 18){
    errors.push("You must be at least 18 years old to sign up.");
   }
   return {errors,isValid: errors.length === 0};
}

module.exports = ageValidator;