import { WEBSOCKET_OPEN, WEBSOCKET_CLOSE } from "../util";
import { CONTROLS_CLOSED, CONTROLS_OPENED } from '../actions/control';

const app = (state = { connecting: true, connected: false, controlsOpened: false }, action) => {
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
        case CONTROLS_OPENED:
            return ({
                ...state,
                controlsOpened: true,
            })
        case CONTROLS_CLOSED:
            return ({
                ...state,
                controlsOpened: false,
            })
        default:
            return state
        }
    }

export default app;