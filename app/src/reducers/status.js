import { WEBSOCKET_MESSAGE } from "../util";

const status = (state = {}, action) => {
    switch (action.type) {
        case WEBSOCKET_MESSAGE:
            return ({
                ...state,
                ...action.payload,
            });
        default:
            return state
        }
    }

export default status;