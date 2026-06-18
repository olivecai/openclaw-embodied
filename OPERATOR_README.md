# openclaw-embodied

1. Clone this repository into /home/$(whoami)/. 

2. Run `cd openclaw-embodied; git submodule init; git submodule update` to pull the differential drive repository.

3. Install OpenClaw. Enter your API key and modify the config.json at path <TODO> to add a model.

models used thus far: <TODO>
- gemini
- deepseek
- etc etc

4. In OpenClaw, run `talk to agent`. There, you can talk to the agent with prompts like:

- "Look side to side, and decide what to do."
- "Give Joe the cup."
