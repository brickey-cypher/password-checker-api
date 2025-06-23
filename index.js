// index.js
const express = require("express");
const { spawn } = require("child_process");
const path = require("path");

const app = express();
app.use(express.json());

app.post("/check", (req, res) => {
  const password = req.body.password;
  if (!password) {
    return res.status(400).json({ error: "Missing password" });
  }

  const checkerPath = path.join(__dirname, "checker");
  const checker = spawn(checkerPath);

  let output = "";
  checker.stdout.on("data", (data) => {
    output += data.toString();
  });

  checker.stderr.on("data", (err) => {
    console.error("Checker error:", err.toString());
  });

  checker.on("close", (code) => {
    if (code !== 0) {
      return res.status(500).json({ error: "Checker process failed" });
    }
      res.json({ result: output.trim() });
    });
  });

