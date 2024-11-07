function copyCode(button) {
    const code = button.previousElementSibling.innerText;
    navigator.clipboard.writeText(code).then(() => {
      button.innerText = "Copied!";
      setTimeout(() => {
        button.innerText = "Copy";
      }, 2000);
    }).catch(err => {
      console.error("Failed to copy text: ", err);
    });
  }
  