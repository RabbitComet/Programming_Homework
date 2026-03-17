function addEmail(email, arr) {
  console.log(`Email ${email} added successfully.`);
  return [arr, email].flat();
}

function removeEmail(email, arr) {
  const index = arr.indexOf(email);
  if (index !== -1) {
    console.log(`Email ${email} removed successfully.`);
    arr.splice(index, 1);
  } else {
    console.log(`Email ${email} not found in the list.`);

  }
  return arr;
}

module.exports = {
  addEmail,
  removeEmail,
};
