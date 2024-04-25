let playerXName = 'Player X';
let playerOName = 'Player O';
let currentPlayer = 'X';
let cells = document.querySelectorAll('.cell');
let board = ['', '', '', '', '', '', '', '', ''];
let winner = null;
let scoreX = 0;
let scoreO = 0;

// Function to start or restart the game
function startGame() {
  currentPlayer = 'X';
  board = ['', '', '', '', '', '', '', '', ''];
  winner = null;
  updateBoardUI();
}

// Function to handle cell click
function cellClicked(index) {
  if (!board[index] && !winner) {
    board[index] = currentPlayer;
    updateBoardUI();
    playClickSound();
    checkWinner();
    currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
  }
}

// Function to check for a winner
function checkWinner() {
  const winConditions = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
  ];

  winConditions.forEach(condition => {
    const [a, b, c] = condition;
    if (board[a] && board[a] === board[b] && board[a] === board[c]) {
      winner = board[a];
      updateScore(winner);
      setTimeout(() => alert(`Player ${winner} (${winner === 'X' ? playerXName : playerOName}) wins!`), 50);
    }
  });

  if (!winner && board.every(cell => cell !== '')) {
    setTimeout(() => alert('It\'s a tie!'), 50);
  }
}

// Function to update the UI based on the board state
function updateBoardUI() {
  cells.forEach((cell, index) => {
    cell.innerText = board[index];
  });
}

// Function to update the score
function updateScore(winner) {
  if (winner === 'X') {
    scoreX++;
  } else if (winner === 'O') {
    scoreO++;
  }
  document.getElementById('score').innerText = `${playerXName}: ${scoreX} | ${playerOName}: ${scoreO}`;
}

// Function to play click sound
function playClickSound() {
  const clickSound = document.getElementById('clickSound');
  clickSound.currentTime = 0;
  clickSound.play();
}

// Initialize the game
startGame();
