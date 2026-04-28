const ageValidator = require("./ageValidator.js");
const emailValidator = require("./mailValidator.js");
const passwordValidator = require("./passwordValidator.js");

const validator = (req, res, next) => {
  const { email, age, password } = req.body;
  const { isValid: isEmailValid, errors: emailErrors } = emailValidator(email);
  const { isValid: isAgeValid, errors: ageErrors } = ageValidator(age);
  const { isValid: isPasswordValid, errors: passwordErrors } = passwordValidator(password);

  if (!isEmailValid || !isAgeValid || !isPasswordValid) {
    const errors = [
      ...emailErrors.map((e) => ({ field: "email", message: e })),
      ...ageErrors.map((e) => ({ field: "age", message: e })),
      ...passwordErrors.map((e) => ({ field: "password", message: e })),
    ];
    return res
      .status(400)
      .json({ status: "error", message: "Validation failed", errors });
  }
  else{
    next();
  }
};

module.exports = validator;