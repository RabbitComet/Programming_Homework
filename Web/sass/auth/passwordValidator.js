function passwordValidator(password) {
    const minLength = 8;
    const hasUpperCase = /[A-Z]/.test(password);
    const hasLowerCase = /[a-z]/.test(password);
    const hasDigit = /\d/.test(password);
    const hasSpecialChar = /[!@#$%^&*(),.?":{}|<>]/.test(password);

    const errors = [];

    if (!password) {
        errors.push("Password is required.");
    }
    if (password.length < minLength) {
        errors.push(`Password must be at least ${minLength} characters long.`);
    }
    if (!hasUpperCase) {
        errors.push("Password must contain at least one uppercase letter.");
    }
    if (!hasLowerCase) {
        errors.push("Password must contain at least one lowercase letter.");
    }
    if (!hasDigit) {
        errors.push("Password must contain at least one digit.");
    }
    if (!hasSpecialChar) {
        errors.push("Password must contain at least one special character.");
    }
    return { errors, isValid: errors.length === 0 };
}

module.exports = passwordValidator;