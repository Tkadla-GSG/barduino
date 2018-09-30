import { WEBSOCKET_OPEN, WEBSOCKET_CLOSE } from "../util";

const app = (state = { connecting: true, connected: false }, action) => {
    switch (action.type) {
        case WEBSOCKET_OPEN:
            return ({
                ...state,
                connecting: false,
                connected: true,
            });
        case WEBSOCKET_CLOSE:
            return ({
                ...state,
                connecting: false,
                connected: false,
            })
        default:
            return state
        }
    }

export default app;