// Simulated attention detection
function detectAttention() {
    return Math.random() * 100;
}

chrome.commands.onCommand.addListener(function (command) {
    if (command === "_execute_browser_action") {
        const attention = detectAttention();
        chrome.browserAction.setBadgeText({ text: attention.toFixed(2) + "%" });
    }
});
