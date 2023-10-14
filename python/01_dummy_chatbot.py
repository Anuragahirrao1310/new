from telegram.ext import Updater, MessageHandler, Filters
import openai

openai.api_key = "<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>"
TELEGRAM_API_TOKEN = "<6208619347:AAEmTZVx1ZFNn6TMpJjdi18ZDlpSZGDD3pA>"

def text_message(update, context):
    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages= [{"role": "system", "content": "Ass a silly phrase after each one of your answers"}]
    )
    update.message.reply_text(response["choices"][0]["message"]["content"])


updater = Updater(TELEGRAM_API_TOKEN, use_context=True)
dispatcher = updater.dispatcher
dispatcher.add_handler(MessageHandler(Filters.text & (~Filters.command), text_message))
updater.start_polling()
updater.idle()