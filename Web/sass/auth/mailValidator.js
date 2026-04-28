function emailValidator(email) {
    const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    const errors = [];

    if (!email) {
        errors.push("Email is required.");
    } else if (!emailRegex.test(email)) {
        errors.push("Invalid email format.");
    }
    return { errors, isValid: errors.length === 0 };
}

module.exports = emailValidator;