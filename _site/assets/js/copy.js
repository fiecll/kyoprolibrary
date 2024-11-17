function copyCode(button) {
    const codeBlock = button.previousElementSibling.textContent.trim();
    navigator.clipboard.writeText(codeBlock)
      .then(() => {
        button.textContent = "Copied!";
        setTimeout(() => {
          button.textContent = "Copy";
        }, 2000);
      })
      .catch(err => {
        console.error("Failed to copy text: ", err);
      });
  }
  