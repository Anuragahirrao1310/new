import openai
import gradio

openai.api_key = "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"

messages = [{"role": "system", "content": "You are a indian god Shiva who is god of gods who solve all problam of its people"}]

def CustomChatGPT(user_input):
    messages.append({"role": "user", "content": user_input})
    response = openai.ChatCompletion.create(
        model = "gpt-3.5-turbo",
        messages = messages
    )
    ChatGPT_reply = response["choices"][0]["message"]["content"]
    messages.append({"role": "assistant", "content": ChatGPT_reply})
    return ChatGPT_reply

demo = gradio.Interface(fn=CustomChatGPT, inputs = "text", outputs = "text", title = "Bhole baba")

demo.launch(share=True)